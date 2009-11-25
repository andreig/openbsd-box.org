use CGI::Simple;

$q = new CGI::Simple;

for ($i=1;$i<17;$i++) {
  open(FILE,"<page-$i.html");
  open(OUT,">Xpage-$i.html");
  $line = <FILE>;
  $line =~ s/<br><br>/<br><br>\n/g;
  $line =~ s/<span/\n<span/g;
  $line =~ s/<\/span>/<\/span>\n/g;
  $line =~ s/<s>//g;
  $line =~ s/<\/s>//g;
  #$line =~ s/^<center.*$/Pagina $i/g;
  $line = $q->url_decode($line);
  print OUT $line;

  close(FILE);
  close(OUT);
  open(IN,"<Xpage-$i.html");
  while ($in = <IN>) {
    if ($in =~ m/^<span/) {
      if ($in =~ m/\s+(Raspuns: .*)<!-/) {
        print $1;
      }
    }
    elsif ($in =~ m/^<center/) {
      next;
    }
    elsif ($in =~ m/^\s*(\d+\.)/) {
      print $1, "&nbsp;";
    }
    else {
      print $in;
      }
  }
  close(IN);
  $line = '';
}

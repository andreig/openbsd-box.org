opendir(DIR,".");
@files = readdir(DIR);
$page = 1;

foreach (@files) {
  if ($_ =~ m/^intre/) {
    print "Processing page $page...";
    open(FILE,">page-$page.html");
    open(SRC,"<$_");
    $count = 0;
    $line = '';
    while ($line = <SRC>) {
      $count++;
      print FILE $line if ($count == 91)
    }
    $page++;
    close(FILE);
    close(SRC);
  }
  print " OK\n";
}


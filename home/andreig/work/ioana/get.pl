for ($i=0;$i<180;$i+=10) {
	$url =
	"\"http://www.cursurimedicina.ro/rezitests2008/intrebari_tema.php?selectionStartIndex=$i&idTema=31&detailed=true&type=&completeText=true\"";
	`wget $url`;
}

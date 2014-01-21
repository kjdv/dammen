#! /bin/bash

echo $1 "->" $2
mkdir -p src/images
n=`echo "$1" | awk '{sub(/.png/,"")}1'`
echo "#include <glib.h>" > $2
gdk-pixbuf-csource --raw --extern --name=`basename $n` $1 | awk '{sub(/const/,"")}1' >> $2


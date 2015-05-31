#!/bit/bash
figlet arXiv
read kwrd

echo =====================================
echo Searching the arXiv for the new stuff.
echo http://arxiv.org/list/astro-ph/new

curl -s http://arxiv.org/list/astro-ph/new | grep -i  $kwrd | grep Title > archivoConLosTitulos.txt
echo =====================================
echo keyword: $kwrd
echo =====================================
nlines= wc -l archivoConLosTitulos.txt  | sed 's/archivoConLosTitulos.txt/articles found./g'
curl -s http://arxiv.org/list/astro-ph/new | grep -i  $kwrd | grep Title | sed 's/<span class="descriptor">Title:<\/span>/-/g'
rm archivoConLosTitulos.txt

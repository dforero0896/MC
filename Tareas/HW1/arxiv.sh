#!/bit/bash
figlet arXiv

echo =====================================
echo Searching the arXiv for the new stuff.
echo http://arxiv.org/list/astro-ph/new

curl -s http://arxiv.org/list/astro-ph/new | grep -i  $1 | grep Title > archivoConLosTitulos.txt
echo =====================================
echo keyword: $1
echo =====================================
nlines= wc -l archivoConLosTitulos.txt  | sed 's/archivoConLosTitulos.txt/articles found./g'
curl -s http://arxiv.org/list/astro-ph/new | grep -i  $1 | grep Title | sed 's/<span class="descriptor">Title:<\/span>/-/g'
rm archivoConLosTitulos.txt

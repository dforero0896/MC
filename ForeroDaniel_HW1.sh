#!/bit/bash
figlet arXiv
read kwrd

echo =====================================
echo Searching the arXiv for the new stuff.
echo http://arxiv.org/list/astro-ph/new
curl -s http://arxiv.org/list/astro-ph/new | grep -i  $kwrd | grep Title
echo =====================================
echo keyword: $kwrd

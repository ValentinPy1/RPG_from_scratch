file_found=$(find . -name '*.o' -o -name 'vgcore.*' -o -name '*~' -o -name '#*#')
if [ -n "$file_found" ]
then
    while IFS= read -r file
    do 
        rm -f ${file}
        echo "${file:2} was removed"
    done <<<"$file_found"
else 
    echo "Repository is already clean asf"
fi

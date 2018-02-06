#pp stands for process picture

#Make directory for .ppm files
#rm -rf images
mkdir -p images

#Compiles c++
#g++ -Wall pp.cpp -o pp

for filetype in jpg jpeg png; do
    if ls *.$filetype 1> /dev/null 2>&1; then
        #Converts filetypes to .ppm
        mogrify -format ppm *.$filetype

        for file in *.ppm; do
            ./pp $file
            mv $file ./images/
        done
    fi
done

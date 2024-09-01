g++ -std=c++20 test.cpp -o test 
./test

if [ $? -eq 0 ]; then
    git add *
    read -p "commit message: " commitMessage
    git commit -m "$commitMessage"
    git push
fi

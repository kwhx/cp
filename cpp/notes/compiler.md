# daily use commands (crafted deliberatively for my own use)

- g++ -std=c++20 -O2 -g -DLOCAL -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -D_GLIBCXX_DEBUG -fsanitize=address,undefined -fno-sanitize-recover=all main.cpp -o main
- g++ -std=c++20 -O2 main.cpp -o main_fast

1. write code
2. run first command on the codefile
3. fix
4. run second command on the same codefile
5. learn, fix, optimise, repeat
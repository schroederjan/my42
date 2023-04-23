# libft_tester (2019+)
Tester for the libft project of 42 school (with personalized leaks checking on
mac, using valgrind on linux) Clone this tester in your libft repository, or
somewhere else and customize the path to your libft project by changing the
LIBFT_PATH variable inside the Makefile.  

## Commands
make m = launch mandatory tests  
make b = launch bonus tests  
make a = launch mandatory tests + bonus tests  
make [function name] = launch associated test ex: `make calloc`  

MOK / MKO = test about your malloc size (this shouldn't be tested by moulinette)  

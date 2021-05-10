all: jasmin

jasmin: jasmin.c mongoose.c mongoose.h
	gcc -o jasmin jasmin.c mongoose.c -D MG_ENABLE_DIRECTORY_LISTING=1
clean:
	rm jasmin
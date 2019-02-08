OBJECTS = lib/libmcp23s17.a lib/libpifacecad.o

#distclean: clean
#	rm -f $(BINARY)

all: lib/libmcp23s17.a lib/libpifacecad.o
	node-gyp configure
	node-gyp build

distclean:
	cd libmcp23s17 && make distclean
	cd libpifacecad && make distclean

clean:
	rm -f $(OBJECTS)
	rm -rf ./build
	cd libmcp23s17 && make clean
	cd libpifacecad && make clean

lib/libmcp23s17.a:
	cd libmcp23s17 && make && make install

lib/libpifacecad.o:
	cd libpifacecad && make
	#gcc -c -o ./lib/libpifacecad.o -Ilib/ ./src/pifacecad.c \
	#&& ar rcs ./lib/libpifacecad.a ./lib/libpifacecad.o




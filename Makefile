OBJECTS = libmcp23s17/libmcp23s17.a libpifacecad/libpifacecad.a

all: $(OBJECTS)
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

libmcp23s17/libmcp23s17.a:
	cd libmcp23s17 && make

libpifacecad/libpifacecad.a:
	cd libpifacecad && make


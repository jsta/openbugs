LDFLAGS = -L ../lib -Wl,-rpath,\$$ORIGIN/../lib -m32 
LIBS = -lOpenBUGS 

all: OpenBUGSCli

OpenBUGSCli:
	$(CC) -o OpenBUGSCli OpenBUGSCli.c $(LDFLAGS) $(LIBS)

version=`echo "modelQuit()" | ./OpenBUGSCli | sed -ne "s/OpenBUGS version \(.*\) rev \(.*\)/\1/p"`

# rm -f commands to remove symlink installed by v3.2.1, since cp -f replaces the target not the link 

install:
	mkdir -p $(DESTDIR)$(bindir) $(DESTDIR)$(libdir) $(DESTDIR)$(datarootdir)/doc/openbugs-$(version) $(DESTDIR)$(mandir)/man1
	rm -f $(DESTDIR)$(bindir)/OpenBUGSCli
	cp -f OpenBUGSCli $(DESTDIR)$(bindir) 
	rm -f $(DESTDIR)$(bindir)/OpenBUGS
	cp -f ../bin/OpenBUGS $(DESTDIR)$(bindir)
	chmod 755 $(DESTDIR)$(bindir)/OpenBUGS $(DESTDIR)$(bindir)/OpenBUGSCli
	cp ../lib/libOpenBUGS.so $(DESTDIR)$(libdir) 
	cp -r ../doc/* $(DESTDIR)$(datarootdir)/doc/openbugs-$(version)
	cp ../doc/OpenBUGS.1 $(DESTDIR)$(mandir)/man1

uninstall: 
	rm -f $(DESTDIR)$(bindir)/OpenBUGS
	rm -f $(DESTDIR)$(bindir)/OpenBUGSCli
	rm -f $(DESTDIR)$(libdir)/libOpenBUGS.so
	rm -rf $(DESTDIR)$(datarootdir)/doc/openbugs-$(version)
	rm -f $(DESTDIR)$(mandir)/man1/OpenBUGS.1

clean:
	rm -f OpenBUGSCli

## Simple test using rats example. Run before make install 

check:
	./OpenBUGSCli < ../doc/testscript.txt

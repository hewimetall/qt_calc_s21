all: install, uninstall, clean, dvi, dist, test, gcov_report

install:
	cmake --build ./cmake-build-debug --target qt_front -j 3

uninstall: clean

clean:
	rm -rf cmake-build-debug
dvi:

dist:

test:

gcov_report:

.PHONY := install, uninstall, clean, dvi, dist, test, gcov_report
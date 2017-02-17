#!/bin/bash
cd wxWidgets/
mkdir gtk-build
cd gtk-build
../configure --with-opengl --enable-unicode --prefix=/usr
make -j4
make install



# Dorin Browser

## ATTENTION
This project has moved to https://github.com/dorin131/dorin-browser

## Screenshot

![Screenshot](https://fodor.org/img/cpp-curlpp-library-static-link/5.png)

## Requirements

QT Creator

`https://www.qt.io/download`

QT libs
```
sudo apt-get install qt5-default
sudo apt-get install build-essential libgl1-mesa-dev
```

Googletest
```
sudo apt-get install libgtest-dev
```
and set `GOOGLETEST_DIR` to `/usr/src/googletest`

Curl
```
sudo apt-get install libcurl4-openssl-dev
```


## Building
You have to first manually build curlpp:
```
cd libs/curlpp-0.8.1
mkdir build && cd build
cmake ..
make
```

Then build project with QT Creator

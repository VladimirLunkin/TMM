# Обнаружение и чтение на видео автомобильных номерных знаков, идентификация и вывод на экран

---

## Установка библиотеки OpenALPR

Установка зависимостей:
```shell
sudo apt-get update
sudo apt-get install libopencv-dev libtesseract-dev git cmake
sudo apt-get install build-essential libleptonica-dev
sudo apt-get install iblog4cplus-dev libcurl3-dev beanstalkd
sudo apt-get install curl
```
Загрузка OpenALPR:
```shell
mkdir /downloads
cd downloads
git clone https://github.com/openalpr/openalpr.git
```
Установка OpenALPR:
```shell
cd openalpr/src
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr -DCMAKE_INSTALL_SYSCONFDIR:PATH=/etc ..
make
make install
```

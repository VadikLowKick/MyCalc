# Используем официальный образ с C++ и CMake
FROM ubuntu:22.04

# Установим необходимые пакеты
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libgtest-dev \
    && apt-get clean

# Google Test компилируется отдельно, его нужно собрать
RUN cd /usr/src/gtest && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    cd lib && \
    cp *.a /usr/lib

# Копируем необходимые файлы в контейнер
COPY .. /app

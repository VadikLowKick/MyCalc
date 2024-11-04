# Используем официальный образ с C++ и CMake
FROM ubuntu:22.04

# Установим необходимые пакеты
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libgtest-dev \
    && apt-get clean

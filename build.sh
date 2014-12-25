#!/bin/bash

# Debian 6 (squeeze)
sudo docker build -t docker_puppet/debian_06 Docker/Debian/06_squeeze;

# Debian 7 (wheezy)
sudo docker build -t docker_puppet/debian_07 Docker/Debian/07_wheezy;

# Debian 8 (jessie)
sudo docker build -t docker_puppet/debian_08 Docker/Debian/08_jessie;

# Ubuntu 10.04 (lucid)
sudo docker build -t docker_puppet/ubuntu_10.04 Docker/Ubuntu/10.04_lucid;

# Ubuntu 12.04 (precise)
sudo docker build -t docker_puppet/ubuntu_12.04 Docker/Ubuntu/12.04_precise;

# Ubuntu 14.04 (trusty)
sudo docker build -t docker_puppet/ubuntu_14.04 Docker/Ubuntu/14.04_trusty;

# CentOS 5 (centos5)
sudo docker build -t docker_puppet/centos_05 Docker/CentOS/05_centos5;

# CentOS 6 (centos6)
sudo docker build -t docker_puppet/centos_06 Docker/CentOS/06_centos6;

# CentOS 7 (centos7)
sudo docker build -t docker_puppet/centos_07 Docker/CentOS/07_centos7;

# Fedora 6 (zod)
sudo docker build -t docker_puppet/fedora_06 Docker/Fedora/06_zod;

# Fedora 12 (constantine)
sudo docker build -t docker_puppet/fedora_12 Docker/Fedora/12_constantine;

# Fedora 19 (schrodinger)
sudo docker build -t docker_puppet/fedora_19 Docker/Fedora/19_schrodinger;


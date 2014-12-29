#!/bin/bash
#title           :docker-build.sh
#description     :Builds images for Docker with `docker build`.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20141226
#version         :0.2
#usage		 :bash docker-build.sh
#notes           :Run docker-install.sh first to install the dependencies.
#bash_version    :4.1.5(1)-release
#==============================================================================

# Set formatting
bold=`tput bold`;
normal=`tput sgr0`;

# Set defaults
build_debian=true;
build_ubuntu=true;
build_centos=true;
build_fedora=false;

# Build Debian images?
while true; do
    read -p "Build ${bold}Debian${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) build_debian=true; break;;
        [Nn]* ) build_debian=false; break;;
        * ) build_debian=true; break;;
    esac
done

# Build Ubuntu images?
while true; do
    read -p "Build ${bold}Ubuntu${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) build_ubuntu=true; break;;
        [Nn]* ) build_ubuntu=false; break;;
        * ) build_ubuntu=true; break;;
    esac
done

# Build CentOS images?
while true; do
    read -p "Build ${bold}CentOS${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) build_centos=true; break;;
        [Nn]* ) build_centos=false; break;;
        * ) build_centos=true; break;;
    esac
done

# Build Fedora images?
while true; do
    read -p "Build ${bold}Fedora${normal} images with Docker? [y/${bold}n${normal}] " yn;
    case $yn in
        [Yy]* ) build_fedora=true; break;;
        [Nn]* ) build_fedora=false; break;;
        * ) build_fedora=false; break;;
    esac
done

# Run Docker build for Debian images
if [ "$build_debian" = true ]; then
    printf "\n\n${bold}Building Debian images with Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Debian 6 (squeeze)
    printf "\n${bold}Debian 6 (squeeze)${normal}\n";
    sudo docker build -t docker_puppet/debian:06_squeeze Docker/Debian/06_squeeze;
    # Debian 7 (wheezy)
    printf "\n${bold}Debian 7 (wheezy)${normal}\n";
    sudo docker build -t docker_puppet/debian:07_wheezy Docker/Debian/07_wheezy;
    # Debian 8 (jessie)
    printf "\n${bold}Debian 8 (jessie)${normal}\n";
    sudo docker build -t docker_puppet/debian:08_jessie Docker/Debian/08_jessie;
fi;

# Run Docker build for Ubuntu images
if [ "$build_ubuntu" = true ]; then
    printf "\n\n${bold}Building Ubuntu images with Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Ubuntu 10.04 (lucid)
    printf "\n${bold}Ubuntu 10.04 (lucid)${normal}\n";
    sudo docker build -t docker_puppet/ubuntu:10.04_lucid Docker/Ubuntu/10.04_lucid;
    # Ubuntu 12.04 (precise)
    printf "\n${bold}Ubuntu 12.04 (precise)${normal}\n";
    sudo docker build -t docker_puppet/ubuntu:12.04_precise Docker/Ubuntu/12.04_precise;
    # Ubuntu 14.04 (trusty)
    printf "\n${bold}Ubuntu 14.04 (trusty)${normal}\n";
    sudo docker build -t docker_puppet/ubuntu:14.04_trusty Docker/Ubuntu/14.04_trusty;
fi;

# Run Docker build for CentOS images
if [ "$build_centos" = true ]; then
    printf "\n\n${bold}Building CentOS images with Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # CentOS 5 (centos5)
    printf "\n${bold}CentOS 5 (centos5)${normal}\n";
    sudo docker build -t docker_puppet/centos:05_centos5 Docker/CentOS/05_centos5;
    # CentOS 6 (centos6)
    printf "\n${bold}CentOS 6 (centos6)${normal}\n";
    sudo docker build -t docker_puppet/centos:06_centos6 Docker/CentOS/06_centos6;
    # CentOS 7 (centos7)
    printf "\n${bold}CentOS 7 (centos7)${normal}\n";
    sudo docker build -t docker_puppet/centos:07_centos7 Docker/CentOS/07_centos7;
fi;

# Run Docker build for Fedora images
if [ "$build_fedora" = true ]; then
    printf "\n\n${bold}Building Fedora images with Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Fedora 6 (zod)
    printf "\n${bold}Fedora 6 (zod)${normal}\n";
    sudo docker build -t docker_puppet/fedora:06_zod Docker/Fedora/06_zod;
    # Fedora 12 (constantine)
    printf "\n${bold}Fedora 12 (constantine)${normal}\n";
    sudo docker build -t docker_puppet/fedora:12_constantine Docker/Fedora/12_constantine;
    # Fedora 19 (schrodinger)
    printf "\n${bold}Fedora 19 (schrodinger)${normal}\n";
    sudo docker build -t docker_puppet/fedora:19_schrodinger Docker/Fedora/19_schrodinger;
fi;

# Show Docker images
printf "\n\n${bold}Showing list of Docker images...${normal}\n";
sudo docker images;

# Instructions
printf "\nType "\""sudo docker run -t -i <REPOSITORY>/<TAG> /bin/bash"\"" to run a image.\n";
printf "Example: sudo docker run -t -i docker_puppet/debian:07_wheezy /bin/bash\n";


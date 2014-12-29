#!/bin/bash
#title           :docker-pull-base.sh
#description     :Pulls base images for Docker with `docker pull`.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20141226
#version         :0.2
#usage		 :bash docker-pull-base.sh
#notes           :Run docker-install.sh first to install the dependencies.
#bash_version    :4.1.5(1)-release
#==============================================================================

# Set formatting
bold=`tput bold`;
normal=`tput sgr0`;

# Set defaults
pull_debian=true;
pull_ubuntu=true;
pull_centos=true;
pull_fedora=false;

# Pull base Debian images?
while true; do
    read -p "Pull base ${bold}Debian${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) pull_debian=true; break;;
        [Nn]* ) pull_debian=false; break;;
        * ) pull_debian=true; break;;
    esac
done

# Pull base Ubuntu images?
while true; do
    read -p "Pull base ${bold}Ubuntu${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) pull_ubuntu=true; break;;
        [Nn]* ) pull_ubuntu=false; break;;
        * ) pull_ubuntu=true; break;;
    esac
done

# Pull base CentOS images?
while true; do
    read -p "Pull base ${bold}CentOS${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) pull_centos=true; break;;
        [Nn]* ) pull_centos=false; break;;
        * ) pull_centos=true; break;;
    esac
done

# Pull base Fedora images?
while true; do
    read -p "Pull base ${bold}Fedora${normal} images with Docker? [y/${bold}n${normal}] " yn;
    case $yn in
        [Yy]* ) pull_fedora=true; break;;
        [Nn]* ) pull_fedora=false; break;;
        * ) pull_fedora=false; break;;
    esac
done

# Run Docker pull for base Debian images
if [ "$pull_debian" = true ]; then
    printf "\n\n${bold}Pulling base Debian images with Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Debian 6 (squeeze)
    printf "\n${bold}Debian 6 (squeeze)${normal}\n";
    sudo docker pull debian:squeeze;
    # Debian 7 (wheezy)
    printf "\n${bold}Debian 7 (wheezy)${normal}\n";
    sudo docker pull debian:wheezy;
    # Debian 8 (jessie)
    printf "\n${bold}Debian 8 (jessie)${normal}\n";
    sudo docker pull debian:jessie;
fi;

# Run Docker pull for base Ubuntu images
if [ "$pull_ubuntu" = true ]; then
    printf "\n\n${bold}Pulling base Ubuntu images with Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Ubuntu 10.04 (lucid)
    printf "\n${bold}Ubuntu 10.04 (lucid)${normal}\n";
    sudo docker pull ubuntu:lucid;
    # Ubuntu 12.04 (precise)
    printf "\n${bold}Ubuntu 12.04 (precise)${normal}\n";
    sudo docker pull ubuntu:precise;
    # Ubuntu 14.04 (trusty)
    printf "\n${bold}Ubuntu 14.04 (trusty)${normal}\n";
    sudo docker pull ubuntu:trusty;
fi;

# Run Docker pull for base CentOS images
if [ "$pull_centos" = true ]; then
    printf "\n\n${bold}Pulling base CentOS images with Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # CentOS 5 (centos5)
    printf "\n${bold}CentOS 5 (centos5)${normal}\n";
    sudo docker pull centos:centos5;
    # CentOS 6 (centos6)
    printf "\n${bold}CentOS 6 (centos6)${normal}\n";
    sudo docker pull centos:centos6;
    # CentOS 7 (centos7)
    printf "\n${bold}CentOS 7 (centos7)${normal}\n";
    sudo docker pull centos:centos7;
fi;

# Run Docker pull for base Fedora images
if [ "$pull_fedora" = true ]; then
    printf "\n\n${bold}Pulling base Fedora images with Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Fedora 6 (zod)
    printf "\n${bold}Fedora 6 (zod)${normal}\n";
    sudo docker pull fedora:zod;
    # Fedora 12 (constantine)
    printf "\n${bold}Fedora 12 (constantine)${normal}\n";
    sudo docker pull fedora:constantine;
    # Fedora 19 (schrodinger)
    printf "\n${bold}Fedora 19 (schrodinger)${normal}\n";
    sudo docker pull fedora:schrodinger;
fi;

# Show Docker images
printf "\n\n${bold}Showing list of Docker images...${normal}\n";
sudo docker images;


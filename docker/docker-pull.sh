#!/bin/bash
#title           :docker-pull.sh
#description     :Pulls original images for Docker with `docker pull`.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20141226
#version         :0.2
#usage		 :bash docker-pull.sh
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

# Pull Debian images?
while true; do
    read -p "Pull ${bold}Debian${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) pull_debian=true; break;;
        [Nn]* ) pull_debian=false; break;;
        * ) pull_debian=true; break;;
    esac
done

# Pull Ubuntu images?
while true; do
    read -p "Pull ${bold}Ubuntu${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) pull_ubuntu=true; break;;
        [Nn]* ) pull_ubuntu=false; break;;
        * ) pull_ubuntu=true; break;;
    esac
done

# Pull CentOS images?
while true; do
    read -p "Pull ${bold}CentOS${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) pull_centos=true; break;;
        [Nn]* ) pull_centos=false; break;;
        * ) pull_centos=true; break;;
    esac
done

# Pull Fedora images?
while true; do
    read -p "Pull ${bold}Fedora${normal} images with Docker? [y/${bold}n${normal}] " yn;
    case $yn in
        [Yy]* ) pull_fedora=true; break;;
        [Nn]* ) pull_fedora=false; break;;
        * ) pull_fedora=false; break;;
    esac
done

# Run Docker pull for Debian images
if [ "$pull_debian" = true ]; then
    printf "\n\n${bold}Pulling Debian images with Docker...${normal}\n";
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

# Run Docker pull for Ubuntu images
if [ "$pull_ubuntu" = true ]; then
    printf "\n\n${bold}Pulling Ubuntu images with Docker...${normal}\n";
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

# Run Docker pull for CentOS images
if [ "$pull_centos" = true ]; then
    printf "\n\n${bold}Pulling CentOS images with Docker...${normal}\n";
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

# Run Docker pull for Fedora images
if [ "$pull_fedora" = true ]; then
    printf "\n\n${bold}Pulling Fedora images with Docker...${normal}\n";
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


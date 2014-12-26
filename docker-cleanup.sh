#!/bin/bash

# Set formatting
bold=`tput bold`
normal=`tput sgr0`

# Set defaults
cleanup_debian=true;
cleanup_ubuntu=true;
cleanup_centos=true;
cleanup_fedora=false;
cleanup_untagged=true;

# Cleanup Debian images?
while true; do
    read -p "Cleanup ${bold}Debian${normal} images of Docker? [${bold}y${normal}/n] " yn
    case $yn in
        [Yy]* ) cleanup_debian=true; break;;
        [Nn]* ) cleanup_debian=false; break;;
        * ) cleanup_debian=true; break;;
    esac
done

# Cleanup Ubuntu images?
while true; do
    read -p "Cleanup ${bold}Ubuntu${normal} images of Docker? [${bold}y${normal}/n] " yn
    case $yn in
        [Yy]* ) cleanup_ubuntu=true; break;;
        [Nn]* ) cleanup_ubuntu=false; break;;
        * ) cleanup_ubuntu=true; break;;
    esac
done

# Cleanup CentOS images?
while true; do
    read -p "Cleanup ${bold}CentOS${normal} images of Docker? [${bold}y${normal}/n] " yn
    case $yn in
        [Yy]* ) cleanup_centos=true; break;;
        [Nn]* ) cleanup_centos=false; break;;
        * ) cleanup_centos=true; break;;
    esac
done

# Cleanup Fedora images?
while true; do
    read -p "Cleanup ${bold}Fedora${normal} images of Docker? [y/${bold}n${normal}] " yn
    case $yn in
        [Yy]* ) cleanup_fedora=true; break;;
        [Nn]* ) cleanup_fedora=false; break;;
        * ) cleanup_fedora=false; break;;
    esac
done

# Cleanup untagged images?
while true; do
    read -p "Cleanup ${bold}untagged${normal} images of Docker? [y/${bold}n${normal}] " yn
    case $yn in
        [Yy]* ) cleanup_untagged=true; break;;
        [Nn]* ) cleanup_untagged=false; break;;
        * ) cleanup_untagged=true; break;;
    esac
done

# Run Docker rmi for Debian images
if [ "$cleanup_debian" = true ]; then
    printf "\n\n${bold}Cleaning Debian images of Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Debian 6 (squeeze)
    printf "\n${bold}Debian 6 (squeeze)${normal}\n";
    sudo docker rmi docker_puppet/debian:06_squeeze;
    # Debian 7 (wheezy)
    printf "\n${bold}Debian 7 (wheezy)${normal}\n";
    sudo docker rmi docker_puppet/debian:07_wheezy;
    # Debian 8 (jessie)
    printf "\n${bold}Debian 8 (jessie)${normal}\n";
    sudo docker rmi docker_puppet/debian:08_jessie;
fi;

# Run Docker rmi for Ubuntu images
if [ "$cleanup_ubuntu" = true ]; then
    printf "\n\n${bold}Cleaning Ubuntu images of Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Ubuntu 10.04 (lucid)
    printf "\n${bold}Ubuntu 10.04 (lucid)${normal}\n";
    sudo docker rmi docker_puppet/ubuntu:10.04_lucid;
    # Ubuntu 12.04 (precise)
    printf "\n${bold}Ubuntu 12.04 (precise)${normal}\n";
    sudo docker rmi docker_puppet/ubuntu:12.04_precise;
    # Ubuntu 14.04 (trusty)
    printf "\n${bold}Ubuntu 14.04 (trusty)${normal}\n";
    sudo docker rmi docker_puppet/ubuntu:14.04_trusty;
fi;

# Run Docker rmi for CentOS images
if [ "$cleanup_centos" = true ]; then
    printf "\n\n${bold}Cleaning CentOS images of Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # CentOS 5 (centos5)
    printf "\n${bold}CentOS 5 (centos5)${normal}\n";
    sudo docker rmi docker_puppet/centos:05_centos5;
    # CentOS 6 (centos6)
    printf "\n${bold}CentOS 6 (centos6)${normal}\n";
    sudo docker rmi docker_puppet/centos:06_centos6;
    # CentOS 7 (centos7)
    printf "\n${bold}CentOS 7 (centos7)${normal}\n";
    sudo docker rmi docker_puppet/centos:07_centos7;
fi;

# Run Docker rmi for Fedora images
if [ "$cleanup_fedora" = true ]; then
    printf "\n\n${bold}Cleaning Fedora images of Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    # Fedora 6 (zod)
    printf "\n${bold}Fedora 6 (zod)${normal}\n";
    sudo docker rmi docker_puppet/fedora:06_zod;
    # Fedora 12 (constantine)
    printf "\n${bold}Fedora 12 (constantine)${normal}\n";
    sudo docker rmi docker_puppet/fedora:12_constantine;
    # Fedora 19 (schrodinger)
    printf "\n${bold}Fedora 19 (schrodinger)${normal}\n";
    sudo docker rmi docker_puppet/fedora:19_schrodinger;
fi;

# Run Docker rmi for untagged images
if [ "$cleanup_untagged" = true ]; then
    printf "\n\n${bold}Cleaning untagged images of Docker...${normal}\n";
    read -p "Press [Enter] key to continue...";
    sudo docker rmi -f $(docker images | grep "^<none>" | awk "{print $3}");
fi;

# Show Docker images
printf "\n\n${bold}Showing list of Docker images...${normal}\n";
sudo docker images


#!/bin/bash
#title		:puppet-build.sh
#description	:Builds Provisionous Docker/Puppet images with
#		 `docker build`.
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141229
#version	:0.4
#usage		:bash puppet-build.sh
#notes		:Run docker-install.sh first to install the dependencies.
#bash_version	:4.1.5(1)-release
#==============================================================================

# Set formatting
bold=`tput bold`;
normal=`tput sgr0`;

# Set defaults
distro_debian_status=true;
distro_debian_title="Docker/Puppet/Debian";
distro_debian_path="debian";
distro_debian_build="debian-build.sh";
distro_ubuntu_status=true;
distro_ubuntu_title="Docker/Puppet/Ubuntu";
distro_ubuntu_path="ubuntu";
distro_ubuntu_build="ubuntu-build.sh";
distro_centos_status=true;
distro_centos_title="Docker/Puppet/CentOS";
distro_centos_path="centos";
distro_centos_build="centos-build.sh";
distro_fedora_status=false;
distro_fedora_title="Docker/Puppet/Fedora";
distro_fedora_path="fedora";
distro_fedora_build="fedora-build.sh";

# Build distro_debian images?
while true; do
    read -p "Build Provisionous ${bold}${distro_debian_title}${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) distro_debian_status=true; break;;
        [Nn]* ) distro_debian_status=false; break;;
        * ) distro_debian_status=true; break;;
    esac
done

# Build distro_ubuntu images?
while true; do
    read -p "Build Provisionous ${bold}${distro_ubuntu_title}${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) distro_ubuntu_status=true; break;;
        [Nn]* ) distro_ubuntu_status=false; break;;
        * ) distro_ubuntu_status=true; break;;
    esac
done

# Build distro_centos images?
while true; do
    read -p "Build Provisionous ${bold}${distro_centos_title}${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) distro_centos_status=true; break;;
        [Nn]* ) distro_centos_status=false; break;;
        * ) distro_centos_status=true; break;;
    esac
done

# Build distro_fedora images?
while true; do
    read -p "Build Provisionous ${bold}${distro_fedora_title}${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) distro_fedora_status=true; break;;
        [Nn]* ) distro_fedora_status=false; break;;
        * ) distro_fedora_status=false; break;;
    esac
done

# Confirm build
printf "\n${bold}Ready to build images...${normal}\n";
read -p "Press [Enter] key to continue...";

# Run build script for distro_debian images
if [ "$distro_debian_status" = true ]; then
    printf "\n${bold}${distro_debian_title}${normal}\n";
    source ./$distro_debian_path/$distro_debian_build;
fi;

# Run build script for distro_ubuntu images
if [ "$distro_ubuntu_status" = true ]; then
    printf "\n${bold}${distro_ubuntu_title}${normal}\n";
    source ./$distro_ubuntu_path/$distro_ubuntu_build;
fi;

# Run build script for distro_centos images
if [ "$distro_centos_status" = true ]; then
    printf "\n${bold}${distro_centos_title}${normal}\n";
    source ./$distro_centos_path/$distro_centos_build;
fi;

# Run build script for distro_fedora images
if [ "$distro_fedora_status" = true ]; then
    printf "\n${bold}${distro_fedora_title}${normal}\n";
    source ./$distro_fedora_path/$distro_fedora_build;
fi;


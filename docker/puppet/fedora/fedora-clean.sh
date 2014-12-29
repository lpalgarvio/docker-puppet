#!/bin/bash
#title		:fedora-clean.sh
#description	:Cleans Provisionous Docker/Puppet/Fedora images with
#		 `docker rmi`.
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141229
#version	:0.4
#usage		:bash fedora-clean.sh
#notes		:Run docker-install.sh first to install the dependencies.
#bash_version	:4.1.5(1)-release
#==============================================================================

# Set formatting
bold=`tput bold`;
normal=`tput sgr0`;

# Set defaults
tag_06_zod_status=true;
tag_06_zod_title="Docker/Puppet/Fedora/6 (zod)";
tag_06_zod_url="solict/provisionous-puppet-fedora:zod";
tag_12_constantine_status=true;
tag_12_constantine_title="Docker/Puppet/Fedora/12 (constantine)";
tag_12_constantine_url="solict/provisionous-puppet-fedora:constantine";
tag_19_schrodinger_status=true;
tag_19_schrodinger_title="Docker/Puppet/Fedora/19 (schrodinger)";
tag_19_schrodinger_url="solict/provisionous-puppet-fedora:schrodinger";

# Clean tag_06_zod image?
while true; do
    read -p "Clean Provisionous ${bold}${tag_06_zod_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_06_zod_status=true; break;;
        [Nn]* ) tag_06_zod_status=false; break;;
        * ) tag_06_zod_status=true; break;;
    esac
done

# Clean tag_12_constantine image?
while true; do
    read -p "Clean Provisionous ${bold}${tag_12_constantine_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_12_constantine_status=true; break;;
        [Nn]* ) tag_12_constantine_status=false; break;;
        * ) tag_12_constantine_status=true; break;;
    esac
done

# Clean tag_19_schrodinger image?
while true; do
    read -p "Clean Provisionous ${bold}${tag_19_schrodinger_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_19_schrodinger_status=true; break;;
        [Nn]* ) tag_19_schrodinger_status=false; break;;
        * ) tag_19_schrodinger_status=true; break;;
    esac
done

# Confirm clean
printf "\n${bold}Ready to clean images...${normal}\n";
read -p "Press [Enter] key to continue...";

# Run `docker rmi` for tag_06_zod image
if [ "$tag_06_zod_status" = true ]; then
    printf "\n${bold}${tag_06_zod_title}${normal}\n";
    sudo docker rmi -f $tag_06_zod_url;
fi;

# Run `docker rmi` for tag_12_constantine image
if [ "$tag_12_constantine_status" = true ]; then
    printf "\n${bold}${tag_12_constantine_title}${normal}\n";
    sudo docker rmi -f $tag_12_constantine_url;
fi;

# Run `docker rmi` for tag_19_schrodinger image
if [ "$tag_19_schrodinger_status" = true ]; then
    printf "\n${bold}${tag_19_schrodinger_title}${normal}\n";
    sudo docker rmi -f $tag_19_schrodinger_url;
fi;


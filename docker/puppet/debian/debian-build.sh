#!/bin/bash
#title		:debian-build.sh
#description	:Builds Provisionous Docker/Puppet/Debian images with
#		 `docker build`.
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141229
#version	:0.4
#usage		:bash debian-build.sh
#notes		:Run docker-install.sh first to install the dependencies.
#bash_version	:4.1.5(1)-release
#==============================================================================

# Set formatting
bold=`tput bold`;
normal=`tput sgr0`;

# Set defaults
tag_06_squeeze_status=true;
tag_06_squeeze_title="Docker/Puppet/Debian/6 (squeeze)";
tag_06_squeeze_url="solict/provisionous-puppet-debian:squeeze";
tag_06_squeeze_path="06_squeeze";
tag_07_wheezy_status=true;
tag_07_wheezy_title="Docker/Puppet/Debian/7 (wheezy)";
tag_07_wheezy_url="solict/provisionous-puppet-debian:wheezy";
tag_07_wheezy_path="07_wheezy";
tag_08_jessie_status=true;
tag_08_jessie_title="Docker/Puppet/Debian/8 (jessie)";
tag_08_jessie_url="solict/provisionous-puppet-debian:jessie";
tag_08_jessie_path="08_jessie";

# Build tag_06_squeeze image?
while true; do
    read -p "Build Provisionous ${bold}${tag_06_squeeze_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_06_squeeze_status=true; break;;
        [Nn]* ) tag_06_squeeze_status=false; break;;
        * ) tag_06_squeeze_status=true; break;;
    esac
done

# Build tag_07_wheezy image?
while true; do
    read -p "Build Provisionous ${bold}${tag_07_wheezy_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_07_wheezy_status=true; break;;
        [Nn]* ) tag_07_wheezy_status=false; break;;
        * ) tag_07_wheezy_status=true; break;;
    esac
done

# Build tag_08_jessie image?
while true; do
    read -p "Build Provisionous ${bold}${tag_08_jessie_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_08_jessie_status=true; break;;
        [Nn]* ) tag_08_jessie_status=false; break;;
        * ) tag_08_jessie_status=true; break;;
    esac
done

# Confirm build
printf "\n${bold}Ready to build images...${normal}\n";
read -p "Press [Enter] key to continue...";

# Run `docker build` for tag_06_squeeze image
if [ "$tag_06_squeeze_status" = true ]; then
    printf "\n${bold}${tag_06_squeeze_title}${normal}\n";
    sudo docker build -t $tag_06_squeeze_url $tag_06_squeeze_path;
fi;

# Run `docker build` for tag_07_wheezy image
if [ "$tag_07_wheezy_status" = true ]; then
    printf "\n${bold}${tag_07_wheezy_title}${normal}\n";
    sudo docker build -t $tag_07_wheezy_url $tag_07_wheezy_path;
fi;

# Run `docker build` for tag_08_jessie image
if [ "$tag_08_jessie_status" = true ]; then
    printf "\n${bold}${tag_08_jessie_title}${normal}\n";
    sudo docker build -t $tag_08_jessie_url $tag_08_jessie_path;
fi;


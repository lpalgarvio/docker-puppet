#!/bin/bash
#title		:centos-build.sh
#description	:Builds Provisionous Docker/Puppet/CentOS images with
#		 `docker build`.
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141229
#version	:0.4
#usage		:bash centos-build.sh
#notes		:Run docker-install.sh first to install the dependencies.
#bash_version	:4.1.5(1)-release
#==============================================================================

# Set formatting
bold=`tput bold`;
normal=`tput sgr0`;

# Set defaults
tag_05_centos5_status=true;
tag_05_centos5_title="Docker/Puppet/CentOS/5 (centos5)";
tag_05_centos5_url="solict/provisionous-puppet-centos:centos5";
tag_05_centos5_path="05_centos5";
tag_06_centos6_status=true;
tag_06_centos6_title="Docker/Puppet/CentOS/6 (centos6)";
tag_06_centos6_url="solict/provisionous-puppet-centos:centos6";
tag_06_centos6_path="06_centos6";
tag_07_centos7_status=true;
tag_07_centos7_title="Docker/Puppet/CentOS/7 (centos7)";
tag_07_centos7_url="solict/provisionous-puppet-centos:centos7";
tag_07_centos7_path="07_centos7";

# Build tag_05_centos5 image?
while true; do
    read -p "Build Provisionous ${bold}${tag_05_centos5_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_05_centos5_status=true; break;;
        [Nn]* ) tag_05_centos5_status=false; break;;
        * ) tag_05_centos5_status=true; break;;
    esac
done

# Build tag_06_centos6 image?
while true; do
    read -p "Build Provisionous ${bold}${tag_06_centos6_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_06_centos6_status=true; break;;
        [Nn]* ) tag_06_centos6_status=false; break;;
        * ) tag_06_centos6_status=true; break;;
    esac
done

# Build tag_07_centos7 image?
while true; do
    read -p "Build Provisionous ${bold}${tag_07_centos7_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_07_centos7_status=true; break;;
        [Nn]* ) tag_07_centos7_status=false; break;;
        * ) tag_07_centos7_status=true; break;;
    esac
done

# Confirm build
printf "\n${bold}Ready to build images...${normal}\n";
read -p "Press [Enter] key to continue...";

# Run `docker build` for tag_05_centos5 image
if [ "$tag_05_centos5_status" = true ]; then
    printf "\n${bold}${tag_05_centos5_title}${normal}\n";
    sudo docker build -t $tag_05_centos5_url $tag_05_centos5_path;
fi;

# Run `docker build` for tag_06_centos6 image
if [ "$tag_06_centos6_status" = true ]; then
    printf "\n${bold}${tag_06_centos6_title}${normal}\n";
    sudo docker build -t $tag_06_centos6_url $tag_06_centos6_path;
fi;

# Run `docker build` for tag_07_centos7 image
if [ "$tag_07_centos7_status" = true ]; then
    printf "\n${bold}${tag_07_centos7_title}${normal}\n";
    sudo docker build -t $tag_07_centos7_url $tag_07_centos7_path;
fi;


#!/bin/bash
#title		:ubuntu-build.sh
#description	:Builds Provisionous Docker/Puppet/Ubuntu images with
#		 `docker build`.
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141229
#version	:0.4
#usage		:bash ubuntu-build.sh
#notes		:Run docker-install.sh first to install the dependencies.
#bash_version	:4.1.5(1)-release
#==============================================================================

# Set formatting
bold=`tput bold`;
normal=`tput sgr0`;

# Set defaults
tag_10_04_lucid_status=true;
tag_10_04_lucid_title="Docker/Puppet/Ubuntu/10.04 (lucid)";
tag_10_04_lucid_url="solict/provisionous-puppet-ubuntu:lucid";
tag_10_04_lucid_path="10.04_lucid";
tag_12_04_precise_status=true;
tag_12_04_precise_title="Docker/Puppet/Ubuntu/12.04 (precise)";
tag_12_04_precise_url="solict/provisionous-puppet-ubuntu:precise";
tag_12_04_precise_path="12.04_precise";
tag_14_04_trusty_status=true;
tag_14_04_trusty_title="Docker/Puppet/Ubuntu/14.04 (trusty)";
tag_14_04_trusty_url="solict/provisionous-puppet-ubuntu:trusty";
tag_14_04_trusty_path="14.04_trusty";

# Build tag_10_04_lucid image?
while true; do
    read -p "Build Provisionous ${bold}${tag_10_04_lucid_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_10_04_lucid_status=true; break;;
        [Nn]* ) tag_10_04_lucid_status=false; break;;
        * ) tag_10_04_lucid_status=true; break;;
    esac
done

# Build tag_12_04_precise image?
while true; do
    read -p "Build Provisionous ${bold}${tag_12_04_precise_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_12_04_precise_status=true; break;;
        [Nn]* ) tag_12_04_precise_status=false; break;;
        * ) tag_12_04_precise_status=true; break;;
    esac
done

# Build tag_14_04_trusty image?
while true; do
    read -p "Build Provisionous ${bold}${tag_14_04_trusty_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_14_04_trusty_status=true; break;;
        [Nn]* ) tag_14_04_trusty_status=false; break;;
        * ) tag_14_04_trusty_status=true; break;;
    esac
done

# Confirm build
printf "\n${bold}Ready to build images...${normal}\n";
read -p "Press [Enter] key to continue...";

# Run `docker build` for tag_10_04_lucid image
if [ "$tag_10_04_lucid_status" = true ]; then
    printf "\n${bold}${tag_10_04_lucid_title}${normal}\n";
    sudo docker build -t $tag_10_04_lucid_url $tag_10_04_lucid_path;
fi;

# Run `docker build` for tag_12_04_precise image
if [ "$tag_12_04_precise_status" = true ]; then
    printf "\n${bold}${tag_12_04_precise_title}${normal}\n";
    sudo docker build -t $tag_12_04_precise_url $tag_12_04_precise_path;
fi;

# Run `docker build` for tag_14_04_trusty image
if [ "$tag_14_04_trusty_status" = true ]; then
    printf "\n${bold}${tag_14_04_trusty_title}${normal}\n";
    sudo docker build -t $tag_14_04_trusty_url $tag_14_04_trusty_path;
fi;


#!/bin/bash
#title		:docker-clean.sh
#description	:Cleans Provisionous Docker images with
#		 `docker rmi`.
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141229
#version	:0.4
#usage		:bash docker-clean.sh
#notes		:Run docker-install.sh first to install the dependencies.
#bash_version	:4.1.5(1)-release
#==============================================================================

# Set formatting
bold=`tput bold`;
normal=`tput sgr0`;

# Set defaults
scm_puppet_status=true;
scm_puppet_title="Docker/Puppet";
scm_puppet_path="puppet";
scm_puppet_clean="puppet-clean.sh";
scm_untagged_status=true;
scm_untagged_title="Untagged Docker";

# Clean scm_puppet images?
while true; do
    read -p "Clean Provisionous ${bold}${scm_puppet_title}${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) scm_puppet_status=true; break;;
        [Nn]* ) scm_puppet_status=false; break;;
        * ) scm_puppet_status=true; break;;
    esac
done

# Clean scm_untagged images?
while true; do
    read -p "Clean Provisionous ${bold}${scm_untagged_title}${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) scm_untagged_status=true; break;;
        [Nn]* ) scm_untagged_status=false; break;;
        * ) scm_untagged_status=true; break;;
    esac
done

# Confirm clean
printf "\n${bold}Ready to clean images...${normal}\n";
read -p "Press [Enter] key to continue...";

# Run clean script for scm_puppet images
if [ "$scm_puppet_status" = true ]; then
    printf "\n${bold}${scm_puppet_title}${normal}\n";
    source ./$scm_puppet_path/$scm_puppet_clean;
fi;

# Run clean script for scm_puppet images
if [ "$scm_untagged_status" = true ]; then
    printf "\n${bold}${scm_untagged_title}${normal}\n";
    sudo docker rmi -f $(docker images | grep "^<none>" | awk "{print $3}");
fi;

# Show Docker images
printf "\n\n${bold}Showing list of Docker images...${normal}\n";
sudo docker images;


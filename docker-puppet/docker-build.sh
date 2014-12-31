#!/bin/bash
#title		:docker-build.sh
#description	:Builds Provisionous Docker images with
#		 `docker build`.
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141229
#version	:0.4
#usage		:bash docker-build.sh
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
scm_puppet_build="puppet-build.sh";

# Build scm_puppet images?
while true; do
    read -p "Build Provisionous ${bold}${scm_puppet_title}${normal} images with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) scm_puppet_status=true; break;;
        [Nn]* ) scm_puppet_status=false; break;;
        * ) scm_puppet_status=true; break;;
    esac
done

# Confirm build
printf "\n${bold}Ready to build images...${normal}\n";
read -p "Press [Enter] key to continue...";

# Run build script for scm_puppet images
if [ "$scm_puppet_status" = true ]; then
    printf "\n${bold}${scm_puppet_title}${normal}\n";
    source ./$scm_puppet_path/$scm_puppet_build;
fi;

# Show Docker images
printf "\n\n${bold}Showing list of Docker images...${normal}\n";
sudo docker images;

# Instructions
printf "\nType "\""sudo docker run -t -i <REPOSITORY>/<TAG> /bin/bash"\"" to run a image.\n";
printf "Example: sudo docker run -t -i solict/provisionous-puppet-debian:wheezy /bin/bash\n";


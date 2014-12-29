#!/bin/bash
#title		:fedora-pull.sh
#description	:Pulls Provisionous Docker/Puppet/Fedora images with
#		 `docker pull`.
#author		:lpalgarvio <"lp.algarvio@gmail.com">
#date		:20141229
#version	:0.4
#usage		:bash fedora-pull.sh
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

# Pull tag_06_zod image?
while true; do
    read -p "Pull Provisionous ${bold}${tag_06_zod_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_06_zod_status=true; break;;
        [Nn]* ) tag_06_zod_status=false; break;;
        * ) tag_06_zod_status=true; break;;
    esac
done

# Pull tag_12_constantine image?
while true; do
    read -p "Pull Provisionous ${bold}${tag_12_constantine_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_12_constantine_status=true; break;;
        [Nn]* ) tag_12_constantine_status=false; break;;
        * ) tag_12_constantine_status=true; break;;
    esac
done

# Pull tag_19_schrodinger image?
while true; do
    read -p "Pull Provisionous ${bold}${tag_19_schrodinger_title}${normal} image with Docker? [${bold}y${normal}/n] " yn;
    case $yn in
        [Yy]* ) tag_19_schrodinger_status=true; break;;
        [Nn]* ) tag_19_schrodinger_status=false; break;;
        * ) tag_19_schrodinger_status=true; break;;
    esac
done

# Confirm pull
printf "\n${bold}Ready to pull images...${normal}\n";
read -p "Press [Enter] key to continue...";

# Run `docker pull` for tag_06_zod image
if [ "$tag_06_zod_status" = true ]; then
    printf "\n${bold}${tag_06_zod_title}${normal}\n";
    sudo docker pull $tag_06_zod_url;
fi;

# Run `docker pull` for tag_12_constantine image
if [ "$tag_12_constantine_status" = true ]; then
    printf "\n${bold}${tag_12_constantine_title}${normal}\n";
    sudo docker pull $tag_12_constantine_url;
fi;

# Run `docker pull` for tag_19_schrodinger image
if [ "$tag_19_schrodinger_status" = true ]; then
    printf "\n${bold}${tag_19_schrodinger_title}${normal}\n";
    sudo docker pull $tag_19_schrodinger_url;
fi;


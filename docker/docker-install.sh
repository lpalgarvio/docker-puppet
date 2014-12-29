#!/bin/bash
#title           :docker-install.sh
#description     :Installs Docker and all the dependencies.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20141226
#version         :0.2
#usage		 :bash docker-install.sh
#notes           :Requires the sudo command and system-info.sh (bundled).
#bash_version    :4.1.5(1)-release
#==============================================================================

# Run system information script
source ./system-info.sh;

# Get Kernel information
get_KERNEL_PRETTY_NAME KERNEL_PRETTY_NAME;

# Get OS information
get_OS_ID OS_ID;
get_OS_VERSION_MAJOR OS_VERSION_MAJOR;
get_OS_CODENAME OS_CODENAME;
get_OS_PRETTY_NAME OS_PRETTY_NAME;

# Print Kernel and OS information
echo "Kernel: "$KERNEL_PRETTY_NAME;
echo "OS: "$OS_PRETTY_NAME;

# TODO: Install packages

# Check if OS is Debian
if [ "$OS_ID" == "debian" ]; then
  # Debian 6 (squeeze)
  if [ "$OS_VERSION_MAJOR" == "6" ] || [ "$OS_CODENAME" == "squeeze" ]; then
    echo "Detected OS Debian 6 (squeeze)";
    echo "Kernel supported for this distribution release, 3.2.x (backports), is not compatible with docker. Aborting."; exit 1;
    #echo "Ready to install dependencies and run docker installation script...";
    #read -p "Press [Enter] key to continue...";
    #command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    #sudo echo "deb http://http.debian.net/debian-backports squeeze-backports main" > /etc/apt/sources.list.d/squeeze-backports.list;
    #sudo apt-get update;
    #sudo apt-get -y install -t squeeze-backports linux-image-amd64;
    #sudo apt-get -y install curl;
    #sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Debian 7 (wheezy)
  elif [ "$OS_VERSION_MAJOR" == "7" ] || [ "$OS_CODENAME" == "wheezy" ]; then
    echo "Detected OS Debian 7 (wheezy)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo echo "deb http://http.debian.net/debian wheezy-backports main" > /etc/apt/sources.list.d/wheezy-backports.list;
    sudo apt-get update;
    sudo apt-get -y install -t wheezy-backports linux-image-amd64;
    sudo apt-get -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Debian 8 (jessie)
  elif [ "$OS_VERSION_MAJOR" == "8" ] || [ "$OS_CODENAME" == "jessie" ]; then
    echo "Detected OS Debian 8 (jessie)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo apt-get update;
    sudo apt-get -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Other versions
  else
    echo "Detected OS Debian unknown version";
    echo "Requirements may not be met. Aborting."; exit 1;
  fi;
fi;

# Check if OS is Ubuntu
if [ "$OS_ID" == "ubuntu" ]; then
  # Ubuntu 10.04 (lucid)
  if [ "$OS_VERSION_MAJOR" == "10.04" ] || [ "$OS_CODENAME" == "lucid" ]; then
    echo "Detected OS Ubuntu 10.04 (lucid)";
    echo "Kernel supported for this distribution release, 3.2.x (backports), is not compatible with docker. Aborting."; exit 1;
    #echo "Ready to install dependencies and run docker installation script...";
    #read -p "Press [Enter] key to continue...";
    #command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    #sudo echo "deb http://archive.ubuntu.com/ubuntu lucid-backports main restricted universe multiverse" > /etc/apt/sources.list.d/lucid-backports.list;
    #sudo apt-get update;
    #sudo apt-get -y install -t lucid-backports linux-image-generic-lts-backport-oneiric;
    #sudo apt-get -y install curl;
    #sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Ubuntu 12.04 (precise)
  elif [ "$OS_VERSION_MAJOR" == "12.04" ] || [ "$OS_CODENAME" == "precise" ]; then
    echo "Detected OS Ubuntu 12.04 (precise)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo echo "deb http://archive.ubuntu.com/ubuntu precise-backports main restricted universe multiverse" > /etc/apt/sources.list.d/precise-backports.list;
    sudo apt-get update;
    sudo apt-get -y install -t precise-backports linux-image-generic-lts-trusty;
    sudo apt-get -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Ubuntu 14.04 (trusty)
  elif [ "$OS_VERSION_MAJOR" == "14.04" ] || [ "$OS_CODENAME" == "trusty" ]; then
    echo "Detected OS Ubuntu 14.04 (trusty)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo apt-get update;
    sudo apt-get -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Other versions
  else
    echo "Detected OS Ubuntu unknown version";
    echo "Requirements may not be met. Aborting."; exit 1;
  fi;
fi;

# Check if OS is Linux Mint
if [ "$OS_ID" == "linuxmint" ]; then
  # Linux Mint 9 (isadora)
  if [ "$OS_VERSION_MAJOR" == "9" ] || [ "$OS_CODENAME" == "isadora" ]; then
    echo "Detected OS Linux Mint 9 (isadora)";
    echo "Kernel supported for this distribution release, 3.2.x (backports), is not compatible with docker. Aborting."; exit 1;
    #echo "Ready to install dependencies and run docker installation script...";
    #read -p "Press [Enter] key to continue...";
    #command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    #sudo echo "deb http://archive.ubuntu.com/ubuntu lucid-backports main restricted universe multiverse" > /etc/apt/sources.list.d/lucid-backports.list;
    #sudo apt-get update;
    #sudo apt-get -y install -t lucid-backports linux-image-generic-lts-backport-oneiric;
    #sudo apt-get -y install curl;
    #sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Linux Mint 13 (maya)
  elif [ "$OS_VERSION_MAJOR" == "13" ] || [ "$OS_CODENAME" == "maya" ]; then
    echo "Detected OS Linux Mint 13 (maya)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo echo "deb http://archive.ubuntu.com/ubuntu precise-backports main restricted universe multiverse" > /etc/apt/sources.list.d/precise-backports.list;
    sudo apt-get update;
    sudo apt-get -y install -t precise-backports linux-image-generic-lts-trusty;
    sudo apt-get -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Linux Mint 17 (qiana)
  elif [ "$OS_VERSION_MAJOR" == "17" ] || [ "$OS_CODENAME" == "qiana" ]; then
    echo "Detected OS Linux Mint 17 (qiana)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo apt-get update;
    sudo apt-get -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Other versions
  else
    echo "Detected OS Linux Mint unknown version";
    echo "Requirements may not be met. Aborting."; exit 1;
  fi;
fi;

# Check if OS is CentOS
if [ "$OS_ID" == "centos" ]; then
  # CentOS 5 (centos5)
  if [ "$OS_VERSION_MAJOR" == "5" ] || [ "$OS_CODENAME" == "centos5" ]; then
    echo "Detected OS CentOS 5 (centos5)";
    echo "Kernel supported for this distribution release, 3.2.x (elrepo), is not compatible with docker. Aborting."; exit 1;
    #echo "Ready to install dependencies and run docker installation script...";
    #read -p "Press [Enter] key to continue...";
    #command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    #sudo wget https://www.elrepo.org/RPM-GPG-KEY-elrepo.org;
    #sudo rpm --import RPM-GPG-KEY-elrepo.org; sudo gpg --import RPM-GPG-KEY-elrepo.org;
    #sudo rpm -Uvh http://www.elrepo.org/elrepo-release-5-5.el5.elrepo.noarch.rpm;
    #sudo yum makecache;
    #sudo yum -y --enablerepo=elrepo-kernel install kernel-lt;
    #sudo yum -y install curl;
    #sudo curl -sSL https://get.docker.com/ | sudo sh;
  # CentOS 6 (centos6)
  elif [ "$OS_VERSION_MAJOR" == "6" ] || [ "$OS_CODENAME" == "centos6" ]; then
    echo "Detected OS CentOS 6 (centos6)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo wget https://www.elrepo.org/RPM-GPG-KEY-elrepo.org;
    sudo rpm --import RPM-GPG-KEY-elrepo.org; sudo gpg --import RPM-GPG-KEY-elrepo.org;
    sudo rpm -Uvh http://www.elrepo.org/elrepo-release-6-6.el6.elrepo.noarch.rpm;
    sudo yum makecache;
    sudo yum -y --enablerepo=elrepo-kernel install kernel-lt;
    sudo yum -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # CentOS 7 (centos7)
  elif [ "$OS_VERSION_MAJOR" == "7" ] || [ "$OS_CODENAME" == "centos7" ]; then
    echo "Detected OS CentOS 7 (centos7)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo yum makecache;
    sudo yum -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Other versions
  else
    echo "Detected OS CentOS unknown version";
    echo "Requirements may not be met. Aborting."; exit 1;
  fi;
fi;

# Check if OS is Fedora
if [ "$OS_ID" == "fedora" ]; then
  # Fedora 6 (zod)
  if [ "$OS_VERSION_MAJOR" == "6" ] || [ "$OS_CODENAME" == "zod" ]; then
    echo "Detected OS Fedora 6 (zod)";
    echo "Distribution is not supported by docker. Aborting."; exit 1;
  # Fedora 12 (constantine)
  elif [ "$OS_VERSION_MAJOR" == "12" ] || [ "$OS_CODENAME" == "constantine" ]; then
    echo "Detected OS Fedora 12 (constantine)";
    echo "Distribution is not supported by docker. Aborting."; exit 1;
  # Fedora 19 (schrodinger)
  elif [ "$OS_VERSION_MAJOR" == "19" ] || [ "$OS_CODENAME" == "schrodinger" ]; then
    echo "Detected OS Fedora 19 (schrodinger)";
    echo "Ready to install dependencies and run docker installation script...";
    read -p "Press [Enter] key to continue...";
    command -v sudo >/dev/null 2>&1 || { echo >&2 "Sudo is required but it's not installed. Aborting."; exit 1; }
    sudo yum makecache;
    sudo yum -y install curl;
    sudo curl -sSL https://get.docker.com/ | sudo sh;
  # Other versions
  else
    echo "Detected OS Fedora unknown version";
    echo "Requirements may not be met. Aborting."; exit 1;
  fi;
fi;


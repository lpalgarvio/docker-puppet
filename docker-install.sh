#!/bin/bash

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
  # Debian 7 (wheezy)
  elif [ "$OS_VERSION_MAJOR" == "7" ] || [ "$OS_CODENAME" == "wheezy" ]; then
    echo "Detected OS Debian 7 (wheezy)";
  # Debian 8 (jessie)
  elif [ "$OS_VERSION_MAJOR" == "8" ] || [ "$OS_CODENAME" == "jessie" ]; then
    echo "Detected OS Debian 7 (wheezy)";
  # Other versions
  else
    echo "Detected OS Debian unknown version";
  fi;
fi;

# Check if OS is Ubuntu
if [ "$OS_ID" == "ubuntu" ]; then
  # Ubuntu 10.04 (lucid)
  if [ "$OS_VERSION_MAJOR" == "10.04" ] || [ "$OS_CODENAME" == "lucid" ]; then
    echo "Detected OS Ubuntu 10.04 (lucid)";
  # Ubuntu 12.04 (precise)
  elif [ "$OS_VERSION_MAJOR" == "12.04" ] || [ "$OS_CODENAME" == "precise" ]; then
    echo "Detected OS Ubuntu 12.04 (precise)";
  # Ubuntu 14.04 (trusty)
  elif [ "$OS_VERSION_MAJOR" == "14.04" ] || [ "$OS_CODENAME" == "trusty" ]; then
    echo "Detected OS Ubuntu 14.04 (trusty)";
  # Other versions
  else
    echo "Detected OS Ubuntu unknown version";
  fi;
fi;

# Check if OS is Linux Mint
if [ "$OS_ID" == "linuxmint" ]; then
  # Linux Mint 9 (isadora)
  if [ "$OS_VERSION_MAJOR" == "9" ] || [ "$OS_CODENAME" == "isadora" ]; then
    echo "Detected OS Linux Mint 9 (isadora)";
  # Linux Mint 13 (maya)
  elif [ "$OS_VERSION_MAJOR" == "13" ] || [ "$OS_CODENAME" == "maya" ]; then
    echo "Detected OS Linux Mint 13 (maya)";
  # Linux Mint 17 (qiana)
  elif [ "$OS_VERSION_MAJOR" == "17" ] || [ "$OS_CODENAME" == "qiana" ]; then
    echo "Detected OS Linux Mint 17 (qiana)";
  # Other versions
  else
    echo "Detected OS Linux Mint unknown version";
  fi;
fi;

# Check if OS is CentOS
if [ "$OS_ID" == "centos" ]; then
  # CentOS 5 (centos5)
  if [ "$OS_VERSION_MAJOR" == "5" ] || [ "$OS_CODENAME" == "centos5" ]; then
    echo "Detected OS CentOS 5 (centos5)";
  # CentOS 6 (centos6)
  elif [ "$OS_VERSION_MAJOR" == "6" ] || [ "$OS_CODENAME" == "centos6" ]; then
    echo "Detected OS CentOS 6 (centos6)";
  # CentOS 7 (centos7)
  elif [ "$OS_VERSION_MAJOR" == "7" ] || [ "$OS_CODENAME" == "centos7" ]; then
    echo "Detected OS CentOS 7 (centos7)";
  # Other versions
  else
    echo "Detected OS CentOS unknown version";
  fi;
fi;

# Check if OS is Fedora
if [ "$OS_ID" == "fedora" ]; then
  # Fedora 6 (zod)
  if [ "$OS_VERSION_MAJOR" == "6" ] || [ "$OS_CODENAME" == "zod" ]; then
    echo "Detected OS Fedora 6 (zod)";
  # Fedora 12 (constantine)
  elif [ "$OS_VERSION_MAJOR" == "12" ] || [ "$OS_CODENAME" == "constantine" ]; then
    echo "Detected OS Fedora 12 (constantine)";
  # Fedora 19 (schrodinger)
  elif [ "$OS_VERSION_MAJOR" == "19" ] || [ "$OS_CODENAME" == "schrodinger" ]; then
    echo "Detected OS Fedora 19 (schrodinger)";
  # Other versions
  else
    echo "Detected OS Fedora unknown version";
  fi;
fi;


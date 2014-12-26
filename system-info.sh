#!/bin/bash

# Create an associative array
declare -A KERNEL;

# Universal: Kernel information
# * any linux distribution
KERNEL[HOST]=$(uname -n);
KERNEL[OS]=$(uname -o);
KERNEL[NAME]=$(uname -s);
KERNEL[VERSION]=$(uname -r);
KERNEL[ARCH]=$(uname -m);
KERNEL[BITS]=$(uname -m | sed 's/x86_//;s/i[3-6]86/32/');
KERNEL[PRETTY_NAME]=$(uname -mrs);

# TODO: MAJOR/MINOR

# Create an associative array
declare -A OS;

# Specific: Redhat/CentOS release file
# * Centos 5 (centos5)
# * Centos 6 (centos6)
# * Centos 7 (centos7)
if [ -f /etc/centos-release ] ; then
  OS[ID]='centos';
  OS[VERSION_ID]=$(egrep -o '[0-9.]{1,}' /etc/centos-release);
  OS[VERSION_MAJOR]=$(echo ${OS[VERSION_ID]} | cut -f1 -d.);
  OS[NAME]=$(egrep -o '^[A-Za-z.]{1,}' /etc/centos-release);
  OS[CODENAME]=${OS[ID]}${OS[VERSION_MAJOR]};
  OS[VERSION]="${OS[VERSION_ID]} (${OS[CODENAME]})";
  OS[PRETTY_NAME]="${OS[NAME]} ${OS[VERSION]}";
fi;

# Specific: Redhat/Fedora release file
# * Fedora 6 (zod)
# * Fedora 12 (constantine)
# * Fedora 19 (schrodinger)
# * and other versions
if [ -f /etc/fedora-release ] ; then
  OS[ID]='fedora';
  OS[VERSION_ID]=$(egrep -o '[0-9.]{1,}' /etc/fedora-release);
  OS[VERSION_MAJOR]=${OS[VERSION_ID]};
  OS[NAME]=$(egrep -o '^[A-Za-z.]{1,}' /etc/fedora-release);
  OS[CODENAME]=$(head -n 1 /etc/issue.net | grep -oP '\(\K[^\)]+');
  OS[VERSION]="${OS[VERSION_ID]} (${OS[CODENAME]})";
  OS[PRETTY_NAME]="${OS[NAME]} ${OS[VERSION]}";
fi;

# Specific Debian version file
# * Debian 6 (squeeze)
# * Debian 7 (wheezy)
# * Debian 8 (jessie)
if [ -f /etc/debian_version ] ; then
  OS[ID]="debian";
  OS[VERSION_ID]=$(cat /etc/debian_version);
  OS[VERSION_MAJOR]=$(echo ${OS[VERSION_ID]} | cut -f1 -d.);
  OS[NAME]=$(sed 's/[0-9]*//g' /etc/issue.net);
  OS[CODENAME]=$(cat /etc/apt/sources.list | rev | cut -d ' ' -f 2 | rev | grep -v 'updates');
  OS[VERSION]="${OS[VERSION_ID]} (${OS[CODENAME]})";
  OS[PRETTY_NAME]=$(awk 'BEGIN{RS=ORS=" "}!a[$0]++' <<< "${OS[NAME]} ${OS[VERSION]}");
fi;

# Specific Ubuntu release file
# * Ubuntu 10.04 (lucid)
# * Ubuntu 12.04 (precise)
# * Ubuntu 14.04 (trusty)
# * and other versions
if [ -f /etc/lsb-release ] ; then
  . /etc/lsb-release;
  OS[ID]=$(echo $DISTRIB_ID | tr '[:upper:]' '[:lower:]');
  OS[VERSION_ID]=$DISTRIB_RELEASE;
  OS[VERSION_MAJOR]=$(echo ${OS[VERSION_ID]} | cut -f1 -d.);
  OS[NAME]=$DISTRIB_ID;
  OS[CODENAME]=$DISTRIB_CODENAME;
  OS[VERSION]="${OS[VERSION_ID]} (${OS[CODENAME]})";
  OS[PRETTY_NAME]="${OS[NAME]} ${OS[VERSION]}";
fi;

# TODO: Interferes with Linux Mint
# Universal: Systemd OS release file
# * Debian 7 (wheezy)
# * Debian 8 (jessie)
# * Ubuntu 12.04 (precise)
# * Ubuntu 14.04 (trusty)
# * and other versions
#if [ -f /etc/os-release ] ; then
#  . /etc/os-release;
#  OS[ID]=$ID;
#  OS[VERSION_ID]=$VERSION_ID;
#  OS[VERSION_MAJOR]=$(echo ${OS[VERSION_ID]} | cut -f1 -d.);
#  OS[NAME]=$NAME;
#  #OS[CODENAME]="";
#  OS[VERSION]="${OS[VERSION_ID]} (${OS[CODENAME]})";
#  OS[PRETTY_NAME]="${OS[NAME]} ${OS[VERSION]}";
#fi;

# TODO: lsb_release

# TODO: facter

# TODO: MINOR

# Get KERNEL HOST
function get_KERNEL_HOST() {
  eval "$1='${KERNEL[HOST]}'";
}

# Get KERNEL OS
function get_KERNEL_OS() {
  eval "$1='${KERNEL[OS]}'";
}

# Get KERNEL NAME
function get_KERNEL_NAME() {
  eval "$1='${KERNEL[NAME]}'";
}

# Get KERNEL VERSION
function get_KERNEL_VERSION() {
  eval "$1='${KERNEL[VERSION]}'";
}

# Get KERNEL ARCH
function get_KERNEL_ARCH() {
  eval "$1='${KERNEL[ARCH]}'";
}

# Get KERNEL BITS
function get_KERNEL_BITS() {
  eval "$1='${KERNEL[BITS]}'";
}

# Get KERNEL PRETTY NAME
function get_KERNEL_PRETTY_NAME() {
  eval "$1='${KERNEL[PRETTY_NAME]}'";
}

# Get OS ID
function get_OS_ID() {
  eval "$1='${OS[ID]}'";
}

# Get OS VERSION ID
function get_OS_VERSION_ID() {
  eval "$1='${OS[VERSION_ID]}'";
}

# Get OS VERSION MAJOR
function get_OS_VERSION_MAJOR() {
  eval "$1='${OS[VERSION_MAJOR]}'";
}

# Get OS NAME
function get_OS_NAME() {
  eval "$1='${OS[NAME]}'";
}

# Get OS CODENAME
function get_OS_CODENAME() {
  eval "$1='${OS[CODENAME]}'";
}

# Get OS VERSION
function get_OS_VERSION() {
  eval "$1='${OS[VERSION]}'";
}

# Get OS PRETTY NAME
function get_OS_PRETTY_NAME() {
  eval "$1='${OS[PRETTY_NAME]}'";
}


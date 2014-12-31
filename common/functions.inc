#!/bin/bash
#title           :functions.inc
#description     :Describes common functions for the main script.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20141231
#version         :0.5
#usage		 :-
#notes           :-
#bash_version    :4.2
#==============================================================================

#
# Core functions
#

# Show argument instructions
function argument_instructions() {
  echo "Usage: `basename $0` {provider} {provisioner} {command} [distribution] [release]";
  echo "Where the following arguments are required:";
  echo "Providers: docker";
  echo "Provisioners: puppet";
  echo "Commands: clean, pull, build";
  echo "These arguments are optional:";
  echo "Distributions: debian, ubuntu, centos, fedora, etc";
  echo "Releases: squeeze, wheezy, jessie, lucid, precise, trusty, etc";
  echo "Example: `basename $0` docker puppet pull debian wheezy";
}

#
# Index distros/tags
#

# Generic: Search for a distro tag
function generic_search_distro_tag {
  # Get the arguments
  local search_distro=${1};
  local search_tag=${2};
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_search_distro_tag ${search_distro} ${search_tag}";
  fi;
  # Get the tags for the distro
  local IFS=',';
  local distro_tags=(${distro_info['tags']});
  # Cycle through distribution tags
  for ((index=0; index<${#distro_tags[@]}; ++index));
  do
    # Get the current tag variable name
    local current_tag='distro_tag_'${distro_tags[$index]};
    # Debugging
    if [ $debug = true ]; then
      eval "echo \(Search\) Tag: \${${current_tag}['desc']}";
    fi;
    # Get the current tag codename
    eval current_codename="\${${current_tag}['codename']}";
    # Compare the current tag with the search tag
    if [ "$current_codename" == "$search_tag" ]; then
      # Get the current tag information
      declare -gA RESULT;
      eval RESULT['status']="\${${current_tag}['status']}";
      eval RESULT['codename']="\${${current_tag}['codename']}";
      eval RESULT['version']="\${${current_tag}['version']}";
      eval RESULT['title']="\${${current_tag}['title']}";
      eval RESULT['desc']="\${${current_tag}['desc']}";
      eval RESULT['url']="\${${current_tag}['url']}";
      eval RESULT['path']="\${${current_tag}['path']}";
      # Debugging
      if [ $debug = true ]; then
        echo "Tag: ${RESULT['desc']}";
      fi;
      # Return success
      return 1;
    fi;
    # Clear variables
    unset $current_codename;
  done;
}

# Generic: Iterate on distro tags
function generic_iterate_distro_tags {
  # Get the arguments
  local arg_distro=${1};
  local call_function=${2};
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_iterate_distro_tags ${arg_distro} ${call_function}";
  fi;
  # Get the tags for the distro
  local IFS=',';
  local distro_tags=(${distro_info['tags']});
  # Cycle through distribution tags
  for ((index=0; index<${#distro_tags[@]}; ++index));
  do
    # Get the current tag variable name
    local current_tag='distro_tag_'${distro_tags[$index]};
    # Debugging
    if [ $debug = true ]; then
      eval "echo \(Iterate\) Tag: \${${current_tag}['codename']}";
    fi;
    # Get the current tag codename
    eval current_codename="\${${current_tag}['codename']}";
    # Call the target function
    "$call_function" $arg_distro $current_codename;
    # Clear variables
    unset $current_codename;
  done;
  # Return success
  return 1;
}

# Generic: Load a distro from configuration file
function generic_load_distro_config {
  # Get arguments
  local arg_provisioner=$1;
  local arg_distro=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_load_distro_config ${arg_provisioner} ${arg_distro}";
    echo "Configuration: $arg_provisioner/${arg_distro}/${arg_distro}.inc";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Import distro configuration
    source "./$arg_provisioner/${arg_distro}/${arg_distro}.inc";
    # Debugging
    if [ $debug = true ]; then
      echo "Distro: ${distro_info['desc']}";
    fi;
  fi;
}

#
# Clean distros/tags
#

# Generic: Clean a tag for a distro
function generic_clean_distro_tag() {
  # Get arguments
  local arg_distro=$1;
  local arg_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_clean_distro_tag ${arg_distro} ${arg_tag}";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_clean_distro_tag $arg_distro $arg_tag;
  fi;
}

# Generic: Clean all the tags for a distro
function generic_clean_distro_tags() {
  # Get arguments
  local arg_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_clean_distro_tags ${arg_distro}";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_clean_distro_tags $arg_distro;
  fi;
}

# Generic: Clean all tags for all distros
function generic_clean_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_clean_distros";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_clean_distros;
  fi;
}

#
# Pull distros/tags
#

# Generic: Pull a tag for a distro
function generic_pull_distro_tag() {
  # Get arguments
  local arg_distro=$1;
  local arg_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_pull_distro_tag ${arg_distro} ${arg_tag}";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_pull_distro_tag $arg_distro $arg_tag;
  fi;
}

# Generic: Pull all the tags for a distro
function generic_pull_distro_tags() {
  # Get arguments
  local arg_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_pull_distro_tags ${arg_distro}";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_pull_distro_tags $arg_distro;
  fi;
}

# Generic: Pull all tags for all distros
function generic_pull_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_pull_distros";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_pull_distros;
  fi;
}

#
# Build distros/tags
#

# Generic: Build a tag for a distro
function generic_build_distro_tag() {
  # Get arguments
  local arg_distro=$1;
  local arg_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_build_distro_tag ${arg_distro} ${arg_tag}";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_build_distro_tag $arg_distro $arg_tag;
  fi;
}

# Generic: Build all the tags for a distro
function generic_build_distro_tags() {
  # Get arguments
  local arg_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_build_distro_tags ${arg_distro}";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_build_distro_tags $arg_distro;
  fi;
}

# Generic: Build all tags for all distros
function generic_build_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_build_distros";
  fi;
  # Docker provider
  if [ "$arg_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_build_distros;
  fi;
}


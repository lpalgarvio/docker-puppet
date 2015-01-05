#!/bin/bash
#title           :docker.inc
#description     :Docker provider functions.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20141231
#version         :0.5
#usage		 :-
#notes           :-
#bash_version    :4.1.5(1)-release
#==============================================================================

#
# Clean distros/tags
#

# Clean a tag for a given distribution
function docker_clean_distro_tag() {
  # Get arguments
  local arg_distro=$1;
  local arg_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_clean_distro_tag ${arg_distro} ${arg_tag}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config 'docker-puppet' $arg_distro;
  # Call function to search for distro tag
  generic_search_distro_tag $arg_distro $arg_tag;
  local retval=$?;
  # Get data
  local tag_title=${RESULT['title']};
  local tag_desc=${RESULT['desc']};
  local tag_url=${RESULT['url']};
  # Clear variables
  unset RESULT;
  # Check if a match was returned
  if [ "$retval" -eq 1 ]; then
    # Run `docker rmi` for a tag
    printf "\n${bold}${tag_desc}${normal}\n";
    echo "sudo docker rmi -f ${tag_url}";
    sudo docker rmi -f ${tag_url};
  else
    # Show error and exit
    echo "No match for distro/tag."; exit $E_BADARGS;
  fi;
}

# Clean all the tags for a given distribution
function docker_clean_distro_tags() {
  # Get arguments
  local arg_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_clean_distro_tags ${arg_distro}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config 'docker-puppet' $arg_distro;
  # Call function to iterate on distro tags
  generic_iterate_distro_tags $arg_distro 'docker_clean_distro_tag';
}

# Clean all tags for all distros
function docker_clean_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_clean_distros";
  fi;
  # TODO
  exit 0;
}

#
# Pull distros/tags
#

# Pull a tag for a given distribution
function docker_pull_distro_tag() {
  # Get arguments
  local arg_distro=$1;
  local arg_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_pull_distro_tag ${arg_distro} ${arg_tag}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config 'docker-puppet' $arg_distro;
  # Call function to search for distro tag
  generic_search_distro_tag $arg_distro $arg_tag;
  local retval=$?;
  # Get data
  local tag_title=${RESULT['title']};
  local tag_desc=${RESULT['desc']};
  local tag_url=${RESULT['url']};
  # Clear variables
  unset RESULT;
  # Check if a match was returned
  if [ "$retval" -eq 1 ]; then
    # Run `docker pull` for tag
    printf "\n${bold}${tag_desc}${normal}\n";
    echo "sudo docker pull ${tag_url}";
    sudo docker pull ${tag_url};
  else
    # Show error and exit
    echo "No match for distro/tag."; exit $E_BADARGS;
  fi;
}

# Pull all the tags for a given distribution
function docker_pull_distro_tags() {
  # Get arguments
  local arg_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_pull_distro_tags ${arg_distro}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config 'docker-puppet' $arg_distro;
  # Call function to iterate on distro tags
  generic_iterate_distro_tags $arg_distro 'docker_pull_distro_tag';
}

# Pull all tags for all distros
function docker_pull_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_pull_distros";
  fi;
  # TODO
  exit 0;
}

#
# Build distros/tags
#

# Build a tag for a given distribution
function docker_build_distro_tag() {
  # Get arguments
  local arg_distro=$1;
  local arg_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_build_distro_tag ${arg_distro} ${arg_tag}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config 'docker-puppet' $arg_distro;
  # Call function to search for distro tag
  generic_search_distro_tag $arg_distro $arg_tag;
  local retval=$?;
  # Get data
  local tag_title=${RESULT['title']};
  local tag_url=${RESULT['url']};
  local tag_path=${RESULT['path']};
  # Clear variables
  unset RESULT;
  # Check if a match was returned
  if [ "$retval" -eq 1 ]; then
    # Run `docker build` for tag
    printf "\n${bold}${tag_desc}${normal}\n";
    echo "sudo docker build -t ${tag_url} ${docker_puppet_path}/${arg_distro}/${tag_path}";
    sudo docker build -t ${tag_url} ${docker_puppet_path}/${arg_distro}/${tag_path};
  else
    # Show error and exit
    echo "No match for distro/tag."; exit $E_BADARGS;
  fi;
}

# Build all the tags for a given distribution
function docker_build_distro_tags() {
  # Get arguments
  local arg_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_build_distro_tags ${arg_distro}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config 'docker-puppet' $arg_distro;
  # Call function to iterate on distro tags
  generic_iterate_distro_tags $arg_distro 'docker_build_distro_tag';
}

# Build all tags for all distros
function docker_build_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_build_distros";
  fi;
  # TODO
  exit 0;
}

#
# Run distros/tags
#

# Run a tag from a given distribution
function docker_run_distro_tag() {
  # Get arguments
  local arg_distro=$1;
  local arg_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: docker_run_distro_tag ${arg_distro} ${arg_tag}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config 'docker-puppet' $arg_distro;
  # Call function to search for distro tag
  generic_search_distro_tag $arg_distro $arg_tag;
  local retval=$?;
  # Get data
  local tag_title=${RESULT['title']};
  local tag_url=${RESULT['url']};
  # Clear variables
  unset RESULT;
  # Check if a match was returned
  if [ "$retval" -eq 1 ]; then
    # Run `docker run` for tag
    printf "\n${bold}${tag_desc}${normal}\n";
    echo "sudo docker run -i -t ${tag_url}";
    sudo docker run -i -t ${tag_url};
  else
    # Show error and exit
    echo "No match for distro/tag."; exit $E_BADARGS;
  fi;
}


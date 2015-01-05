#!/bin/bash
#title           :functions.inc
#description     :Describes common functions for the main script.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20150105
#version         :0.6
#usage		 :-
#notes           :-
#bash_version    :4.2
#==============================================================================

#
# Core functions
#

# Show argument instructions
function argument_instructions() {
  echo "Usage: `basename $0` {provisioner} {command} [distribution] [release]";
  echo "Where the following arguments are required:";
  echo "Provisioners: docker-base, docker-puppet";
  echo "Commands: clean, pull, build, run";
  echo "These arguments are optional:";
  echo "Distributions: debian, ubuntu, centos, fedora, etc";
  echo "Releases: squeeze, wheezy, jessie, lucid, precise, trusty, etc";
  echo "Example: `basename $0` docker-puppet pull debian wheezy";
}

#
# Index distros/tags
#

# Generic: Search for a distro tag
function generic_search_distro_tag {
  # Get the arguments
  local pass_distro=${1};
  local pass_tag=${2};
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_search_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Get the tags for the distro
  local IFS=',';
  local distro_tags=(${distro_info['tags']});
  # Cycle through distro tags
  for ((index=0; index<${#distro_tags[@]}; ++index));
  do
    # Get the current tag variable name
    local current_tag='distro_tag_'${distro_tags[$index]};
    # Debugging
    if [ $debug = true ]; then
      eval "echo \(Search\) Tag: \${${current_tag}['desc']}";
    fi;
    # Get the current tag codename
    eval local current_codename="\${${current_tag}['codename']}";
    # Compare the current tag with the search tag
    if [ "$current_codename" == "$pass_tag" ]; then
      # Get the current tag information
      declare -gA RESULT;
      eval RESULT['status']="\${${current_tag}['status']}";
      eval RESULT['codename']="\${${current_tag}['codename']}";
      eval RESULT['version']="\${${current_tag}['version']}";
      eval RESULT['title']="\${${current_tag}['title']}";
      eval RESULT['desc']="\${${current_tag}['desc']}";
      eval RESULT['url']="\${${current_tag}['url']}";
      eval RESULT['dir']="\${${current_tag}['dir']}";
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
  local pass_distro=${1};
  local call_function=${2};
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_iterate_distro_tags ${pass_distro} ${call_function}";
  fi;
  # Get the tags for the distro
  local IFS=',';
  local distro_tags=(${distro_info['tags']});
  # Cycle through distro tags
  for ((index=0; index<${#distro_tags[@]}; ++index));
  do
    # Get the current tag variable name
    local current_tag='distro_tag_'${distro_tags[$index]};
    # Debugging
    if [ $debug = true ]; then
      eval "echo \(Iterate\) Tag: \${${current_tag}['codename']}";
    fi;
    # Get the current tag codename
    eval local current_codename="\${${current_tag}['codename']}";
    # Call the target function
    "$call_function" $pass_distro $current_codename;
    # Clear variables
    unset $current_codename;
  done;
  # Return success
  return 1;
}

# Generic: Load a distro from configuration file
function generic_load_distro_config {
  # Get arguments
  local pass_distro=$1;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    local provision_path="${docker_base_path}/${pass_distro}";
    local provision_inc="${provision_path}/${pass_distro}.${script_ext}";
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    local provision_path="${docker_puppet_path}/${pass_distro}";
    local provision_inc="${provision_path}/${pass_distro}.${script_ext}";
  fi;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_load_distro_config ${pass_distro}";
    echo "Configuration: ${distro_info['inc']}";
  fi;
  # Import distro configuration
  source "./${provision_inc}";
  # Add data to distro array
  distro_info['path']="${provision_path}";
  distro_info['inc']="${provision_inc}";
  # Debugging
  if [ $debug = true ]; then
    echo "Distro: ${distro_info['desc']}";
  fi;
}

#
# Clean distros/tags
#

# Generic: Clean a tag for a distro
function generic_clean_distro_tag() {
  # Get arguments
  local pass_distro=$1;
  local pass_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_clean_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call equivalent function
    docker_clean_distro_tag $pass_distro $pass_tag;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_clean_distro_tag $pass_distro $pass_tag;
  fi;
}

# Generic: Clean all the tags for a distro
function generic_clean_distro_tags() {
  # Get arguments
  local pass_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_clean_distro_tags ${pass_distro}";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call equivalent function
    docker_clean_distro_tags $pass_distro;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_clean_distro_tags $pass_distro;
  fi;
}

# Generic: Clean all tags for all distros
function generic_clean_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_clean_distros";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call equivalent function
    docker_clean_distros;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
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
  local pass_distro=$1;
  local pass_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_pull_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call equivalent function
    docker_pull_distro_tag $pass_distro $pass_tag;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_pull_distro_tag $pass_distro $pass_tag;
  fi;
}

# Generic: Pull all the tags for a distro
function generic_pull_distro_tags() {
  # Get arguments
  local pass_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_pull_distro_tags ${pass_distro}";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call equivalent function
    docker_pull_distro_tags $pass_distro;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_pull_distro_tags $pass_distro;
  fi;
}

# Generic: Pull all tags for all distros
function generic_pull_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_pull_distros";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call equivalent function
    docker_pull_distros;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
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
  local pass_distro=$1;
  local pass_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_build_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call function to show arguments and exit
    echo "Nothing to build."; argument_instructions; exit $E_BADARGS;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_build_distro_tag $pass_distro $pass_tag;
  fi;
}

# Generic: Build all the tags for a distro
function generic_build_distro_tags() {
  # Get arguments
  local pass_distro=$1;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_build_distro_tags ${pass_distro}";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call function to show arguments and exit
    echo "Nothing to build."; argument_instructions; exit $E_BADARGS;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_build_distro_tags $pass_distro;
  fi;
}

# Generic: Build all tags for all distros
function generic_build_distros() {
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_build_distros";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call function to show arguments and exit
    echo "Nothing to build."; argument_instructions; exit $E_BADARGS;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_build_distros;
  fi;
}

#
# Run distros/tags
#

# Generic: Run a tag from a distro
function generic_run_distro_tag() {
  # Get arguments
  local pass_distro=$1;
  local pass_tag=$2;
  # Debugging
  if [ $debug = true ]; then
    echo "Function: generic_run_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Docker-Base provisioner
  if [ "$args_provisioner" == 'docker-base' ]; then
    # Call equivalent function
    docker_run_distro_tag $pass_distro $pass_tag;
  # Docker-Puppet provisioner
  elif [ "$args_provisioner" == 'docker-puppet' ]; then
    # Call equivalent function
    docker_run_distro_tag $pass_distro $pass_tag;
  fi;
}


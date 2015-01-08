#!/bin/bash
#title           :functions.inc
#description     :Describes common functions.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20150108
#version         :0.9
#usage		 :-
#notes           :-
#bash_version    :4.2
#==============================================================================

#
# Core functions
#

# Initialize formatting
function init_formatting() {
  # Style formatting
  style_normal=$(tput sgr0);		# Reset
  style_underline=$(tput sgr 0 1);	# Underline
  style_bold=$(tput bold);		# Bold
  # Color formatting
  color_black=$(tput setaf 0);		# Black
  color_red=$(tput setaf 1);		# Red
  color_green=$(tput setaf 2);		# Green
  color_yellow=$(tput setaf 3);		# Yellow
  color_blue=$(tput setaf 4);		# Blue
  color_purple=$(tput setaf 5);		# Purple
  color_cyan=$(tput setaf 6);		# Cyan
  color_white=$(tput setaf 7);		# White
  # Bundles
  txt_normal="${style_normal}${color_white}";
  txt_error="${style_bold}${color_red}";
  txt_warn="${style_bold}${color_yellow}";
  txt_info="${style_bold}${color_blue}";
  txt_success="${style_bold}${color_green}";
  txt_special1="${style_bold}${color_purple}";
  txt_special2="${style_normal}${color_cyan}";
}

# Show error message and quit
function message_error() {
  # Get the arguments
  local pass_arg1=${1};
  local pass_arg2=${2};
  # Show the error with formatting
  echo -e "${txt_error}${pass_arg1} ${txt_normal}${pass_arg2}";
  # Show usage instructions
  menu_usage;
  # Quit with error
  exit $E_BADARGS;
}

# Show warning message
function message_warn() {
  # Get the arguments
  local pass_arg1=${1};
  local pass_arg2=${2};
  # Show the warn with formatting
  echo -e "${txt_warn}${pass_arg1} ${txt_normal}${pass_arg2}";
}

# Show info message
function message_info() {
  # Get the arguments
  local pass_arg1=${1};
  local pass_arg2=${2};
  # Show the info with formatting
  echo -e "${txt_info}${pass_arg1} ${txt_normal}${pass_arg2}";
}

# Show success message
function message_success() {
  # Get the arguments
  local pass_arg1=${1};
  local pass_arg2=${2};
  # Show the success with formatting
  echo -e "${txt_success}${pass_arg1} ${txt_normal}${pass_arg2}";
}

# Show question yes/no
function question_yn() {
  # Get the arguments
  local pass_question=${1};
  # Show question with prompt
  local RESULT;
  while true; do
    read -p "${txt_warn}$pass_question${txt_warn} [${bold}y${normal}/n] " yn;
    case $yn in
      [Yy]* ) $RESULT=true; break;;
      [Nn]* ) $RESULT=false; break;;
      * ) $RESULT=true; break;;
    esac
  done
  return $RESULT;
}

# Show quick usage message
function menu_usage() {
  echo -e "${txt_special1}Usage: ${txt_normal}`basename $0` [options] {command} {provisioner} [distribution] [tag]";
}

# Show long help message
function menu_help() {
  echo -e "${txt_special1}Usage: ${txt_normal}`basename $0` [options] {command} {provisioner} [distribution] [tag]";
  echo -e "${txt_normal}";
  echo -e "${txt_special1}Options: ${txt_normal}";
  echo -e "${txt_normal}  -u, --usage                 show the quick usage message";
  echo -e "${txt_normal}  -h, --help                  show this long help message";
  echo -e "${txt_normal}  -a, --all=boolean           select all tags for operation";
  echo -e "${txt_normal}  -f, --force=boolean         force operation and overwrite files";
  echo -e "${txt_normal}";
  echo -e "${txt_special1}Commands (*): ${txt_normal}";
  echo -e "${txt_normal}  cleanup                     remove untagged distro/tag images from local environment";
  echo -e "${txt_normal}  clean {dist} [tag]          remove distro/tag images from local environment";
  echo -e "${txt_normal}  pull {dist} [tag]           retrieve distro/tag images from remote server";
  echo -e "${txt_normal}  build {dist} [tag]          build distro/tag images on local environment";
  echo -e "${txt_normal}  run {dist} {tag}            run distro/tag images on local environment";
  echo -e "${txt_normal}";
  echo -e "${txt_special1}Provisioners (*): ${txt_normal}";
  echo -e "${txt_normal}  docker-base                 docker + base distro/tag images";
  echo -e "${txt_normal}  docker-puppet               docker + puppet distro/tag images";
  echo -e "${txt_normal}";
  echo -e "${txt_special1}Distributions and tags: ${txt_normal}";
  echo -e "${txt_normal}╔═════════╦═══════════════╦═══════════╗";
  echo -e "${txt_normal}║ distro  ║  t.codename   ║ t.version ║";
  echo -e "${txt_normal}║═════════╬═══════════════╬═══════════╣";
  echo -e "${txt_normal}║         ║  squeeze      ║     6     ║";
  echo -e "${txt_normal}║ debian  ║  wheezy       ║     7     ║";
  echo -e "${txt_normal}║         ║  jessie       ║     8     ║";
  echo -e "${txt_normal}╠═════════╬═══════════════╬═══════════╣";
  echo -e "${txt_normal}║         ║  lucid        ║   10.04   ║";
  echo -e "${txt_normal}║ ubuntu  ║  precise      ║   12.04   ║";
  echo -e "${txt_normal}║         ║  trusty       ║   14.04   ║";
  echo -e "${txt_normal}╠═════════╬═══════════════╬═══════════╣";
  echo -e "${txt_normal}║         ║  centos5      ║     5     ║";
  echo -e "${txt_normal}║ centos  ║  centos6      ║     6     ║";
  echo -e "${txt_normal}║         ║  centos7      ║     7     ║";
  echo -e "${txt_normal}╚═════════╩═══════════════╩═══════════╝";
  echo -e "${txt_normal}";
  echo -e "${txt_normal}(*) Required arguments.${txt_normal}";
  echo -e "${txt_normal}";
  echo -e "${txt_special2}Example #1: ${txt_normal}`basename $0` --all=true pull docker-base debian";
  echo -e "${txt_special2}Example #2: ${txt_normal}`basename $0` pull docker-puppet debian wheezy";
  echo -e "${txt_special2}Example #3: ${txt_normal}`basename $0` --force=true clean docker-puppet debian";
}

#
# Index provisions
#

# Generic: Search for a provision
function generic_search_provision {
  # Get the arguments
  local pass_provision=${1};
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_search_provision ${pass_provision}";
  fi;
  # Get the provisions
  local IFS=',';
  local provisions=(${provision_info['provisions']});
  # Cycle through provisions
  for ((index=0; index<${#provisions[@]}; ++index));
  do
    # Get the current provision variable name
    local current_provision='provision_'${provisions[$index]};
    # Debugging
    if [ "$debug" = true ]; then
      eval "message_info '(Search) Provision:' \"\${${current_provision}['desc']}\"";
    fi;
    # Get the current provision codename
    eval local current_codename="\${${current_provision}['codename']}";
    # Compare the current provision with the search provision
    if [ "$current_codename" == "$pass_provision" ]; then
      # Get the current provision information
      declare -gA RESULT;
      eval RESULT['status']="\${${current_provision}['status']}";
      eval RESULT['codename']="\${${current_provision}['codename']}";
      eval RESULT['title']="\${${current_provision}['title']}";
      eval RESULT['desc']="\${${current_provision}['desc']}";
      eval RESULT['provisioner']="\${${current_provision}['provisioner']}";
      eval RESULT['dir']="\${${current_provision}['dir']}";
      # Debugging
      if [ "$debug" = true ]; then
        message_info 'Provision:' "${RESULT['desc']}";
      fi;
      # Return success
      return 1;
    fi;
    # Clear variables
    unset current_codename;
  done;
}

# Generic: Load a provision from configuration file
function generic_load_provision_config {
  # Get arguments
  local pass_provision=$1;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_load_provision_config ${pass_provision}";
  fi;
  # Call function to search for provision
  generic_search_provision $pass_provision;
  local retval=$?;
  # Store provision data
  provision_info['status']=${RESULT['status']};
  provision_info['codename']=${RESULT['codename']};
  provision_info['title']=${RESULT['title']};
  provision_info['desc']=${RESULT['desc']};
  provision_info['provisioner']=${RESULT['provisioner']};
  provision_info['dir']=${RESULT['dir']};
  # Add paths to provision array
  provision_info['provision_path']="${provisions_path}/${provision_info['dir']}";
  provision_info['container_path']="${containers_path}/${provision_info['dir']}";
  # Clear variables
  unset RESULT;
  # Check if a match was returned
  if [ ! "$retval" -eq 1 ]; then
    # Call function to show error and quit
    message_error 'No match for provision.';
  fi;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Provision:' "${provision_info['provision_path']}";
    message_info 'Container' "${provision_info['container_path']}";
  fi;
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
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_search_distro_tag ${pass_distro} ${pass_tag}";
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
    if [ "$debug" = true ]; then
      eval "message_info '(Search) Tag:' \"\${${current_tag}['desc']}\"";
    fi;
    # Get the current tag version and codename
    eval local current_version="\${${current_tag}['version']}";
    eval local current_codename="\${${current_tag}['codename']}";
    # Compare the current tag with the search tag
    if [ "$current_version" == "$pass_tag" ] || [ "$current_codename" == "$pass_tag" ]; then
      # Get the current tag information
      declare -gA RESULT;
      eval RESULT['status']="\${${current_tag}['status']}";
      eval RESULT['codename']="\${${current_tag}['codename']}";
      eval RESULT['version']="\${${current_tag}['version']}";
      eval RESULT['title']="\${${current_tag}['title']}";
      eval RESULT['desc']="\${${current_tag}['desc']}";
      eval RESULT['url']="\${${current_tag}['url']}";
      eval RESULT['shell']="\${${current_tag}['shell']}";
      eval RESULT['provision']="\${${current_tag}['provision']}";
      eval RESULT['provision_dir']="\${${current_tag}['provision_dir']}";
      eval RESULT['container']="\${${current_tag}['container']}";
      eval RESULT['container_dir']="\${${current_tag}['container_dir']}";
      eval RESULT['container_mnt']="\${${current_tag}['container_mnt']}";
      # Debugging
      if [ "$debug" = true ]; then
        message_info 'Tag:' "${RESULT['desc']}";
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
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_iterate_distro_tags ${pass_distro} ${call_function}";
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
    if [ "$debug" = true ]; then
      eval "message_info '(Iterate) Tag:' \"\${${current_tag}['codename']}\"";
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
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_load_distro_config ${pass_distro}";
  fi;
  # Define paths
  local provision_path="${provision_info['provision_path']}/${pass_distro}";
  local provision_inc="${provision_path}/${pass_distro}.${script_ext}";
  local container_path="${provision_info['container_path']}/${pass_distro}";
  # Import distro provision
  source "./${provision_inc}";
  # Add paths to distro array
  distro_info['provision_path']="${provision_path}";
  distro_info['provision_inc']="${provision_inc}";
  distro_info['container_path']="${container_path}";
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Provision:' "${distro_info['provision_inc']}";
    message_info 'Container' "${distro_info['container_path']}";
    message_info 'Distro:' "${distro_info['desc']}";
  fi;
}

#
# Clean distros/tags
#

# Generic: Clean all untagged tags/distros
function generic_clean_untagged() {
  # Get arguments
  local pass_provisioner=$1;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_clean_untagged ${pass_provisioner}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
    # Call equivalent function
    docker_clean_untagged;
  fi;
}

# Generic: Clean a tag for a distro
function generic_clean_distro_tag() {
  # Get arguments
  local pass_provisioner=$1;
  local pass_distro=$2;
  local pass_tag=$3;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_clean_distro_tag ${pass_provisioner} ${pass_distro} ${pass_tag}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
    # Call equivalent function
    docker_clean_distro_tag $pass_distro $pass_tag;
  fi;
}

# Generic: Clean all the tags for a distro
function generic_clean_distro_tags() {
  # Get arguments
  local pass_provisioner=$1;
  local pass_distro=$2;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_clean_distro_tags ${pass_provisioner} ${pass_distro}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
    # Call equivalent function
    docker_clean_distro_tags $pass_distro;
  fi;
}

# Generic: Clean all tags for all distros
function generic_clean_distros() {
  # Get arguments
  local pass_provisioner=$1;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_clean_distros ${pass_provisioner}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
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
  local pass_provisioner=$1;
  local pass_distro=$2;
  local pass_tag=$3;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_pull_distro_tag ${pass_provisioner} ${pass_distro} ${pass_tag}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
    # Call equivalent function
    docker_pull_distro_tag $pass_distro $pass_tag;
  fi;
}

# Generic: Pull all the tags for a distro
function generic_pull_distro_tags() {
  # Get arguments
  local pass_provisioner=$1;
  local pass_distro=$2;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_pull_distro_tags ${pass_provisioner} ${pass_distro}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
    # Call equivalent function
    docker_pull_distro_tags $pass_distro;
  fi;
}

# Generic: Pull all tags for all distros
function generic_pull_distros() {
  # Get arguments
  local pass_provisioner=$1;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_pull_distros ${pass_provisioner}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
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
  local pass_provisioner=$1;
  local pass_distro=$2;
  local pass_tag=$3;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_build_distro_tag ${pass_provisioner} ${pass_distro} ${pass_tag}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
    # Call equivalent function
    docker_build_distro_tag $pass_distro $pass_tag;
  fi;
}

# Generic: Build all the tags for a distro
function generic_build_distro_tags() {
  # Get arguments
  local pass_provisioner=$1;
  local pass_distro=$2;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_build_distro_tags ${pass_provisioner} ${pass_distro}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
    # Call equivalent function
    docker_build_distro_tags $pass_distro;
  fi;
}

# Generic: Build all tags for all distros
function generic_build_distros() {
  # Get arguments
  local pass_provisioner=$1;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_build_distros ${pass_provisioner}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
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
  local pass_provisioner=$1;
  local pass_distro=$2;
  local pass_tag=$3;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "generic_run_distro_tag ${pass_provisioner} ${pass_distro} ${pass_tag}";
  fi;
  # Docker provisioner
  if [ "$pass_provisioner" == 'docker' ]; then
    # Call equivalent function
    docker_run_distro_tag $pass_distro $pass_tag;
  fi;
}


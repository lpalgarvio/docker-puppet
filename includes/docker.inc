#!/bin/bash
#title           :docker-puppet.inc
#description     :Docker-Puppet provider functions.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20150105
#version         :0.6
#usage		 :-
#notes           :-
#bash_version    :4.1.5(1)-release
#==============================================================================

#
# Validate options
#
function docker_validate_options() {
  # Check the command
  case $args_command in
    # Cleanup untagged distro/tag command
    'cleanup' )
      # Check for invalid option `all`
      if [ ! "$opts_all" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--all';
      fi;
      # Check for valid option `force`
      if [ ! "$opts_force" = true ] && [ ! "$opts_force" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--force';
      fi;
      ;;
    # Clean distro/tag command
    'clean' )
      # Check for invalid option `all`
      if [ ! "$opts_all" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--all';
      fi;
      # Check for valid option `force`
      if [ ! "$opts_force" = true ] && [ ! "$opts_force" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--force';
      fi;
      ;;
    # Pull distro/tag command
    'pull' )
      # Check for valid option `all`
      if [ ! "$opts_all" = true ] && [ ! "$opts_all" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--all';
      fi;
      # Check for invalid option `force`
      if [ ! "$opts_force" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--force';
      fi;
      ;;
    # Build distro/tag command
    'build' )
      # Check for invalid option `all`
      if [ ! "$opts_all" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--all';
      fi;
      # Check for valid option `force`
      if [ ! "$opts_force" = true ] && [ ! "$opts_force" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--force';
      fi;
      ;;
    # Run distro/tag command
    'run' )
      # Check for invalid option `all`
      if [ ! "$opts_all" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--all';
      fi;
      # Check for invalid option `force`
      if [ ! "$opts_force" = false ]; then
        # Call function to show error and quit
        message_error 'An invalid option was provided:' '--force';
      fi;
      ;;
  esac;
}

#
# Clean distros/tags
#

# Clean all untagged tags/distros
function docker_clean_untagged() {
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_clean_untagged";
  fi;
  # Call function to validate options
  docker_validate_options;
  # Start building command
  local command_prefix="sudo docker rmi";
  # No opts
  local command_opts="";
  # Add forced removal mode to opts if enabled
  if [ "$opts_force" = true ]; then
    local command_opts="${command_opts} --force";
  fi;
  # Add external command to args
  local command_args="\$(docker images | grep \"^<none>\" | awk \"{print \$3}\")";
  # Generate command
  local command="${command_prefix} ${command_opts} ${command_args}";
  # Execute command
  message_warn '\nSelection:' "Untagged tags/distros";
  message_warn 'Executing:' "${command}\n";
  eval "${command}";
}

# Clean a tag for a distro
function docker_clean_distro_tag() {
  # Get arguments
  local pass_distro=$1;
  local pass_tag=$2;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_clean_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Call function to validate options
  docker_validate_options;
  # Call function to load a distro from configuration file
  generic_load_distro_config $pass_distro;
  # Call function to search for distro tag
  generic_search_distro_tag $pass_distro $pass_tag;
  local retval=$?;
  # Get data from tag array
  local tag_title=${RESULT['title']};
  local tag_desc=${RESULT['desc']};
  local tag_url=${RESULT['url']};
  # Clear variables
  unset RESULT;
  # Start building command
  local command_prefix="sudo docker rmi";
  # No opts
  local command_opts="";
  # Add forced removal mode to opts if enabled
  if [ "$opts_force" = true ]; then
    local command_opts="${command_opts} --force";
  fi;
  # Add tag url to args
  local command_args="${tag_url}";
  # Generate command
  local command="${command_prefix} ${command_opts} ${command_args}";
  # Check if a match was returned
  if [ "$retval" -eq 1 ]; then
    # Execute command
    message_warn '\nSelection:' "${tag_desc}";
    message_warn 'Executing:' "${command}\n";
    eval "${command}";
  else
    # Call function to show error and quit
    message_error 'No match for distro/tag.';
  fi;
}

# Clean all the tags for a distro
function docker_clean_distro_tags() {
  # Get arguments
  local pass_distro=$1;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_clean_distro_tags ${pass_distro}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config $pass_distro;
  # Call function to iterate on distro tags
  generic_iterate_distro_tags $pass_distro 'docker_clean_distro_tag';
}

# Clean all tags for all distros
function docker_clean_distros() {
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_clean_distros";
  fi;
  # TODO
  exit 0;
}

#
# Pull distros/tags
#

# Pull a tag for a distro
function docker_pull_distro_tag() {
  # Get arguments
  local pass_distro=$1;
  local pass_tag=$2;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_pull_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Call function to validate options
  docker_validate_options;
  # Call function to load a distro from configuration file
  generic_load_distro_config $pass_distro;
  # Call function to search for distro tag
  generic_search_distro_tag $pass_distro $pass_tag;
  local retval=$?;
  # Get data from tag array
  local tag_title=${RESULT['title']};
  local tag_desc=${RESULT['desc']};
  local tag_url=${RESULT['url']};
  # Clear variables
  unset RESULT;
  # Start building command
  local command_prefix="sudo docker pull";
  # No opts
  local command_opts="";
  # Add tag url to args
  local command_args="${tag_url}";
  # Generate command
  local command="${command_prefix} ${command_opts} ${command_args}";
  # Check if a match was returned
  if [ "$retval" -eq 1 ]; then
    # Execute command
    message_warn '\nSelection:' "${tag_desc}";
    message_warn 'Executing:' "${command}\n";
    eval "${command}";
  else
    # Call function to show error and quit
    message_error 'No match for distro/tag.';
  fi;
}

# Pull all the tags for a distro
function docker_pull_distro_tags() {
  # Get arguments
  local pass_distro=$1;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_pull_distro_tags ${pass_distro}";
  fi;
  # Call function to validate options
  docker_validate_options;
  # Call function to load a distro from configuration file
  generic_load_distro_config $pass_distro;
  # Option `all` triggered, skip docker_pull_distro_tag()
  if [ "$opts_all" = true ]; then
    # Start building command
    local command_prefix="sudo docker pull";
    # Add all tags mode to opts
    local command_opts="${command_opts} --all-tags";
    # Add distro codename to args
    local command_args="${distro_info['codename']}";
    # Generate command
    local command="${command_prefix} ${command_opts} ${command_args}";
    # Execute command
    message_warn '\nSelection:' "all tags for ${distro_info['codename']}";
    message_warn 'Executing:' "${command}\n";
    eval "${command}";
  # Option `all` is off
  else
    # Call function to iterate on distro tags
    generic_iterate_distro_tags $pass_distro 'docker_pull_distro_tag';
  fi;
}

# Pull all tags for all distros
function docker_pull_distros() {
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_pull_distros";
  fi;
  # TODO
  exit 0;
}

#
# Build distros/tags
#

# Build a tag for a distro
function docker_build_distro_tag() {
  # Get arguments
  local pass_distro=$1;
  local pass_tag=$2;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_build_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Call function to validate options
  docker_validate_options;
  # Call function to load a distro from configuration file
  generic_load_distro_config $pass_distro;
  # Call function to search for distro tag
  generic_search_distro_tag $pass_distro $pass_tag;
  local retval=$?;
  # Get data from tag array
  local tag_title=${RESULT['title']};
  local tag_url=${RESULT['url']};
  local tag_provision=${RESULT['provision']};
  local tag_provision_dir=${RESULT['provision_dir']};
  local tag_provision_path="${distro_info['provision_path']}/${tag_provision_dir}";
  # Clear variables
  unset RESULT;
  # Check if provision is disabled
  if [ "$tag_provision" = false ]; then
    # Call function to show error and quit
    message_error 'Distro/tag not configured for provisioning.';
  fi;
  # Start building command
  local command_prefix="sudo docker build";
  # Add self-clean mode to opts
  local command_opts="--rm=true";
  # Add forced self-clean mode to opts if enabled
  if [ "$opts_force" = true ]; then
    local command_opts="${command_opts} --force-rm";
  fi;
  # Add tag to opts
  local command_opts="${command_opts} --tag=\"${tag_url}\"";
  # Add provision to args
  local command_args="${tag_provision_path}";
  # Generate command
  local command="${command_prefix} ${command_opts} ${command_args}";
  # Check if a match was returned
  if [ "$retval" -eq 1 ]; then
    # Execute command
    message_warn '\nSelection:' "${tag_desc}";
    message_warn 'Executing:' "${command}\n";
    eval "${command}";
  else
    # Call function to show error and quit
    message_error 'No match for distro/tag.';
  fi;
}

# Build all the tags for a distro
function docker_build_distro_tags() {
  # Get arguments
  local pass_distro=$1;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_build_distro_tags ${pass_distro}";
  fi;
  # Call function to load a distro from configuration file
  generic_load_distro_config $pass_distro;
  # Call function to iterate on distro tags
  generic_iterate_distro_tags $pass_distro 'docker_build_distro_tag';
}

# Build all tags for all distros
function docker_build_distros() {
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_build_distros";
  fi;
  # TODO
  exit 0;
}

#
# Run distros/tags
#

# Run a tag from a distro
function docker_run_distro_tag() {
  # Get arguments
  local pass_distro=$1;
  local pass_tag=$2;
  # Debugging
  if [ "$debug" = true ]; then
    message_info 'Function:' "docker_run_distro_tag ${pass_distro} ${pass_tag}";
  fi;
  # Call function to validate options
  docker_validate_options;
  # Call function to load a distro from configuration file
  generic_load_distro_config $pass_distro;
  # Call function to search for distro tag
  generic_search_distro_tag $pass_distro $pass_tag;
  local retval=$?;
  # Get data from tag array
  local tag_title=${RESULT['title']};
  local tag_url=${RESULT['url']};
  local tag_shell=${RESULT['shell']};
  local tag_container=${RESULT['container']};
  local tag_container_dir=${RESULT['container_dir']};
  local tag_container_mnt=${RESULT['container_mnt']};
  local tag_container_path="${distro_info['container_path']}/${tag_container_dir}";
  # Clear variables
  unset RESULT;
  # Start building command
  local command_prefix="sudo docker run";
  # Add interactive and tty modes to opts
  local command_opts="--interactive --tty";
  # Add volume/container to opts if enabled
  if [ "$tag_container" = true ]; then
    local pwd=`pwd`;
    local command_opts="${command_opts} --volume=\"${pwd}/${tag_container_path}\":${tag_container_mnt}:rw";
  fi;
  # Add url and shell to args
  local command_args="${tag_url} ${tag_shell}";
  # Generate command
  local command="${command_prefix} ${command_opts} ${command_args}";
  # Check if a match was returned
  if [ "$retval" -eq 1 ]; then
    # Execute command
    message_warn '\nSelection:' "${tag_desc}";
    message_warn 'Executing:' "${command}\n";
    eval "${command}";
  else
    # Call function to show error and quit
    message_error 'No match for distro/tag.';
  fi;
}


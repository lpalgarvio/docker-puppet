#!/bin/bash
#title           :provisionous.sh
#description     :Provisionous: Operates providers and provisioners.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20150105
#version         :0.6
#usage		 :bash provisionous.sh [options] {provisioner} {command} \
#                  [distribution] [tag]
#notes		 :Run scripts in install directory to install the dependencies.
#bash_version    :4.2
#==============================================================================

#
# Initialization
#

# Import global configuration
source "./config.inc";

# Import scripts
source "./${functions_inc}";

# Initialize formatting
init_formatting;

# Get the options
declare -g opts='';
opts=`getopt --options "u,h,a,f" --longoptions "usage,help,all:,force:" -- "$@"`;

# Validate the options
if [ $? != 0 ]; then
  # Call function to show error and quit
  message_error 'An invalid option was provided:' "${1} ${2}";
fi;

# Store the options
eval set -- "$opts";
while true ; do
  case "$1" in
    # Option `usage`
    -u|--usage )
      menu_usage;
      exit 1;
      ;;
    # Option `help`
    -h|--help )
      menu_help;
      exit 1;
      ;;
    # Option `all`
    -a|--all )
      # True
      if [ "$2" == '--' ]; then
        # Enable option
        opts_all=true;
        options+=$1;
        # Shift positions
        shift 1;
      # True
      elif [ "$2" = true ]; then
        # Enable option
        opts_all=true;
        options+=$1;
        # Shift positions
        shift 2;
      # False
      elif [ "$2" = false ]; then
        # Disable option
        opts_all=false;
        options+=$1;
        # Shift positions
        shift 2;
      # Invalid
      else
        # Call function to show error and quit
        message_error 'An invalid option was provided:' "${1} ${2}";
      fi;
      ;;
    # Option `force`
    -f|--force )
      # True
      if [ "$2" == '--' ]; then
        # Enable option
        opts_force=true;
        options+=$1;
        # Shift positions
        shift 1;
      # True
      elif [ "$2" = true ]; then
        # Enable option
        opts_force=true;
        options+=$1;
        # Shift positions
        shift 2;
      # False
      elif [ "$2" = false ]; then
        # Disable option
        opts_force=false;
        options+=$1;
        # Shift positions
        shift 2;
      # Invalid
      else
        # Call function to show error and quit
        message_error 'An invalid option was provided:' "${1} ${2}";
      fi;
      ;;
    # Don't stall
    --)
      # Shift positions
      shift;
      break;;
  esac;
done;

# Store the arguments
declare -g arguments="$*";
declare -g args_provisioner=$1;
declare -g args_command=$2;
declare -g args_distro=$3;
declare -g args_tag=$4;

# Debugging
if [ "$debug" = true ]; then
  message_info 'Options:' ${options};
  message_info 'Arguments:' ${arguments};
fi;

#
# Logic
#

# Validate provisioner
case $args_provisioner in
  # Docker-Base provisioner
  'docker-base' )
    # Import scripts
    source "./${docker_inc}";
    ;;
  # Docker-Puppet provisioner
  'docker-puppet' )
    # Import scripts
    source "./${docker_inc}";
    ;;
  # Empty argument
  '' )
    # Call function to show error and quit
    message_error 'No provisioner was provided.';
    ;;
  # Any argument
  * )
    # Call function to show error and quit
    message_error 'An invalid provisioner was provided.';
    ;;
esac;

# Validate command
case $args_command in
  # Cleanup untagged distro/tag command
  'cleanup' )
    # Distro and tag not provided
    if [ ! -n "$args_distro" ] && [ ! -n "$args_tag" ]; then
      # Call function to clean all tags for all distros
      generic_clean_untagged;
    # Invalid arguments
    else
      # Call function to show error and quit
      message_error 'Invalid arguments.';
    fi;
    ;;
  # Clean distro/tag command
  'clean' )
    # Distro and tag provided
    if [ -n "$args_distro" ] && [ -n "$args_tag" ]; then
      # Call function to clean a tag for a distro
      generic_clean_distro_tag $args_distro $args_tag;
    # Distro provided, tag not provided
    elif [ -n "$args_distro" ] && [ ! -n "$args_tag" ]; then
      # Call function to clean all tags for a distro
      generic_clean_distro_tags $args_distro;
    # Distro and tag not provided
    elif [ ! -n "$args_distro" ] && [ ! -n "$args_tag" ]; then
      # Call function to clean all tags for all distros
      generic_clean_distros;
    # Invalid arguments
    else
      # Call function to show error and quit
      message_error 'Invalid arguments.';
    fi;
    ;;
  # Pull distro/tag command
  'pull' )
    # Distro and tag provided
    if [ -n "$args_distro" ] && [ -n "$args_tag" ]; then
      # Call function to pull a tag for a distro
      generic_pull_distro_tag $args_distro $args_tag;
    # Distro provided, tag not provided
    elif [ -n "$args_distro" ] && [ ! -n "$args_tag" ]; then
      # Call function to pull all tags for a distro
      generic_pull_distro_tags $args_distro;
    # Distro and tag not provided
    elif [ ! -n "$args_distro" ] && [ ! -n "$args_tag" ]; then
      # Call function to pull all tags for all distros
      generic_pull_distros;
    # Invalid arguments
    else
      # Call function to show error and quit
      message_error 'Invalid arguments.';
    fi;
    ;;
  # Build distro/tag command
  'build' )
    # Distro and tag provided
    if [ -n "$args_distro" ] && [ -n "$args_tag" ]; then
      # Call function to build a tag for a distro
      generic_build_distro_tag $args_distro $args_tag;
    # Distro provided, tag not provided
    elif [ -n "$args_distro" ] && [ ! -n "$args_tag" ]; then
      # Call function to build all tags for a distro
      generic_build_distro_tags $args_distro;
    # Distro and tag not provided
    elif [ ! -n "$args_distro" ] && [ ! -n "$args_tag" ]; then
      # Call function to build all tags for all distros
      generic_build_distros;
    # Invalid arguments
    else
      # Call function to show error and quit
      message_error 'Invalid arguments.';
    fi;
    ;;
  # Run distro/tag command
  'run' )
    # Distro and tag provided
    if [ -n "$args_distro" ] && [ -n "$args_tag" ]; then
      # Call function to run a tag from a distro
      generic_run_distro_tag $args_distro $args_tag;
    # Distro provided, tag not provided
    # Distro and tag not provided
    # Invalid arguments
    else
      # Call function to show error and quit
      message_error 'Invalid arguments.';
    fi;
    ;;
  # Empty argument
  '' )
    # Call function to show error and quit
    message_error 'No command was provided.';
    ;;
  # Invalid arguments
  * )
    # Call function to show error and quit
    message_error 'An invalid command was provided.';
    ;;
esac;

# END
exit;


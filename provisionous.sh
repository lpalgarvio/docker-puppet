#!/bin/bash
#title           :provisionous.sh
#description     :Provisionous: Operates providers and provisioners.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20150105
#version         :0.6
#usage		 :bash provisionous.sh [arg1] [arg2] [arg3] [arg4]
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

# Store the arguments
declare -g args_all="$*";
declare -g args_provisioner=$1;
declare -g args_command=$2;
declare -g args_distro=$3;
declare -g args_tag=$4;

# Debugging
if [ $debug = true ]; then
  echo "Arguments: ${args_all}";
fi;

#
# Decision-makers
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
    # Call function to show arguments and exit
    echo "No provisioner was provided."; argument_instructions; exit $E_BADARGS;
    ;;
  # Any argument
  * )
    # Call function to show arguments and exit
    echo "An invalid provisioner was provided."; argument_instructions; exit $E_BADARGS;
    ;;
esac;

# Validate command
case $args_command in
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
      # Call function to show arguments and exit
      echo "Invalid arguments."; argument_instructions; exit $E_BADARGS;
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
      # Call function to show arguments and exit
      echo "Invalid arguments."; argument_instructions; exit $E_BADARGS;
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
      # Call function to show arguments and exit
      echo "Invalid arguments."; argument_instructions; exit $E_BADARGS;
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
      # Call function to show arguments and exit
      echo "Invalid arguments."; argument_instructions; exit $E_BADARGS;
    fi;
    ;;
  # Empty argument
  '' )
    # Call function to show arguments and exit
    echo "No command was provided."; argument_instructions; exit $E_BADARGS;
    ;;
  # Any argument
  * )
    # Call function to show arguments and exit
    echo "An invalid command was provided."; argument_instructions; exit $E_BADARGS;
    ;;
esac;

# END
exit;


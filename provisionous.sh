#!/bin/bash
#title           :provisionous.sh
#description     :Provisionous: Operates providers and provisioners.
#author		 :lpalgarvio <"lp.algarvio@gmail.com">
#date            :20141231
#version         :0.5
#usage		 :bash provisionous.sh [arg1] [arg2] [arg3] [arg4]
#notes		 :Run docker-install.sh first to install the dependencies.
#bash_version    :4.1.5(1)-release
#==============================================================================

#
# Load configuration and scripts
#

# Import global configuration
source "./config.inc";

# Debugging
if [ $debug = true ]; then
  echo "Configuration: ${common_path}/functions.inc";
fi;
# Import scripts
source "./${common_path}/functions.inc";

# Debugging
if [ $debug = true ]; then
  echo "Arguments: $*";
fi;
# Store the arguments
args="$*";
arg_provisioner=$1;
arg_command=$2;
arg_distro=$3;
arg_tag=$4;

# Validate provisioner
case $arg_provisioner in
  # Docker-Puppet provisioner
  'docker-puppet' )
    # Debugging
    if [ $debug = true ]; then
      echo "Provisioner: ${docker_puppet_path}/docker-puppet.inc";
    fi;
    # Import scripts
    source "./${docker_puppet_path}/docker-puppet.inc";
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
case $arg_command in
  # Clean distro/tag command
  'clean' )
    # Distro and tag provided
    if [ -n "$arg_distro" ] && [ -n "$arg_tag" ]; then
      # Call function to clean a tag for a distro
      generic_clean_distro_tag $arg_distro $arg_tag;
    # Distro provided, tag not provided
    elif [ -n "$arg_distro" ] && [ ! -n "$arg_tag" ]; then
      # Call function to clean all tags for a distro
      generic_clean_distro_tags $arg_distro;
    # Distro and tag not provided
    elif [ ! -n "$arg_distro" ] && [ ! -n "$arg_tag" ]; then
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
    if [ -n "$arg_distro" ] && [ -n "$arg_tag" ]; then
      # Call function to pull a tag for a distro
      generic_pull_distro_tag $arg_distro $arg_tag;
    # Distro provided, tag not provided
    elif [ -n "$arg_distro" ] && [ ! -n "$arg_tag" ]; then
      # Call function to pull all tags for a distro
      generic_pull_distro_tags $arg_distro;
    # Distro and tag not provided
    elif [ ! -n "$arg_distro" ] && [ ! -n "$arg_tag" ]; then
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
    if [ -n "$arg_distro" ] && [ -n "$arg_tag" ]; then
      # Call function to build a tag for a distro
      generic_build_distro_tag $arg_distro $arg_tag;
    # Distro provided, tag not provided
    elif [ -n "$arg_distro" ] && [ ! -n "$arg_tag" ]; then
      # Call function to build all tags for a distro
      generic_build_distro_tags $arg_distro;
    # Distro and tag not provided
    elif [ ! -n "$arg_distro" ] && [ ! -n "$arg_tag" ]; then
      # Call function to build all tags for all distros
      generic_build_distros;
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


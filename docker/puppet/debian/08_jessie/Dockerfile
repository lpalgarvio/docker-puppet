###############################################################################
# Docker profile
# OS: Debian 8 (jessie)
# Equivalent: Ubuntu 12.04 (trusty)
###############################################################################

FROM debian:jessie
MAINTAINER Luís Pedro Algarvio <lp.algarvio@gmail.com>

# Configure the enviroment
ENV TERM linux
RUN export DEBIAN_FRONTEND="noninteractive";
WORKDIR /root

# Configure Apt
RUN echo "APT::Install-Recommends "\""false"\"";" >> /etc/apt/apt.conf;
RUN echo "APT::Install-Suggests "\""false"\"";" >> /etc/apt/apt.conf;

# Clear and Update the Apt cache
RUN ["/bin/bash", "-c", "if [ ! -f /var/lib/apt/lists/lock ]; then \
  apt-get clean all; apt-get update; fi;"]

# Install system dependencies
RUN apt-get -qqy install apt-utils dialog bash-completion wget nano;

# Configure /root profile
RUN cp -R /etc/skel/. /root;

# Upgrade the Apt packages
RUN apt-get -qqy upgrade;

# Install Ruby and Rubygems
RUN apt-get -qqy install ruby ruby-dev rubygems-integration;

# Configure Rubygems
RUN echo "gem: --no-ri --no-rdoc" > ~/.gemrc;

# Install Puppet
RUN apt-get -qqy install puppet;

# Install system dependencies
RUN apt-get -qqy install make gcc;

# Install Librarian for Puppet
RUN gem install librarian-puppet;


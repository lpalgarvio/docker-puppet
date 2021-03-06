###############################################################################
# Provisionous Docker/Puppet profile
# OS: Ubuntu 14.04 (trusty)
# Equivalent: Debian 8 (jessie)
###############################################################################

FROM ubuntu:trusty
MAINTAINER Luís Pedro Algarvio <lp.algarvio@gmail.com>

#
# Environment
#

ENV TERM linux
RUN export DEBIAN_FRONTEND="noninteractive";
RUN mkdir -p /root/setup;
WORKDIR /root/setup

#
# Package Management System initialization
#

# Configure the PMS
RUN echo "APT::Install-Recommends "\""false"\"";" >> /etc/apt/apt.conf && \
    echo "APT::Install-Suggests "\""false"\"";" >> /etc/apt/apt.conf;

# Clear and Update the PMS cache if it is outdated
RUN ["/bin/bash", "-c", "if [ \
    \"$(stat -c %Y /var/lib/apt/lists/partial)\" -lt \
    \"$(date +\"%s\" -d \"-3 days\")\" \
    ]; then apt-get clean; apt-get update; \
    else echo \"PMS caches are up-to-date.\"; fi;"]

#
# System dependencies and upgrades
#

# Install system dependencies
RUN apt-get -qy install apt-utils debianutils dialog \
    gnupg ca-certificates wget curl make gcc tar procps \
    bash-completion nano && \
    apt-get clean;

# Replace /root files with files from /etc/skel
RUN cp -R /etc/skel/. /root;

# Upgrade the packages
RUN apt-get -qy upgrade && \
    apt-get clean;

#
# Repositories and GPG keys
#

# Update keys
RUN gpg --refresh-keys && \
    apt-key update;

# Puppet key/repo, for updated Puppet packages
RUN gpg --keyserver keys.gnupg.net --recv-keys 4BD6EC30 && \
    apt-key adv --keyserver keys.gnupg.net --recv-keys 4BD6EC30 && \
    wget -q http://apt.puppetlabs.com/puppetlabs-release-trusty.deb && \
    dpkg -i puppetlabs-release-trusty.deb && \
    apt-get clean;

# Update the PMS cache
RUN apt-get update;

#
# Ruby (via PMS)
#

# Install Ruby 1.9.x (from main)
RUN apt-get -qy install ruby1.9.3 ruby1.9.1-dev rubygems-integration && \
    apt-get clean;

#
# Puppet (via PMS)
#

# Install Puppet 3.7.x (from puppetlabs)
RUN apt-get -qy install puppet && \
    apt-get clean;

#
# Rubygems (via rubygems)
#

# Configure Rubygems
RUN echo "gem: --no-ri --no-rdoc" > ~/.gemrc;

# Install Bundler latest gem
RUN /bin/bash -l -c "gem install bundler";

# Install Librarian-puppet 2.0.1 (for ruby >=1.9.x) gems
RUN /bin/bash -l -c "gem install librarian-puppet -v 2.0.1";


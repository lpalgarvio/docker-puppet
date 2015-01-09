###############################################################################
# Provisionous Docker/Puppet profile
# OS: Debian 6 (squeeze)
# Equivalent: Ubuntu 10.04 (lucid)
###############################################################################

FROM debian:squeeze
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
RUN apt-get -qqy install apt-utils dialog bash-completion gnupg wget nano \
    make gcc tar procps debianutils && \
    apt-get clean;

# Replace /root files with files from /etc/skel
RUN cp -R /etc/skel/. /root;

# Upgrade the packages
RUN apt-get -qqy upgrade && \
    apt-get clean;

#
# Repositories and GPG keys
#

# Update keys
RUN gpg --refresh-keys && \
    apt-key update;

# Bearstech key/repo, for updated Ruby packages
RUN gpg --keyserver keys.gnupg.net --recv-keys 90158EE0 && \
    apt-key adv --keyserver keys.gnupg.net --recv-keys 90158EE0;
RUN ["/bin/bash", "-c", "echo \"deb \
    http://deb.bearstech.com/debian \
    squeeze-bearstech   main\" > \
    /etc/apt/sources.list.d/bearstech.list;"]

# Puppet key/repo, for updated Puppet packages
RUN gpg --keyserver keys.gnupg.net --recv-keys 4BD6EC30 && \
    apt-key adv --keyserver keys.gnupg.net --recv-keys 4BD6EC30 && \
    wget -q http://apt.puppetlabs.com/puppetlabs-release-squeeze.deb && \
    dpkg -i puppetlabs-release-squeeze.deb && \
    apt-get clean;

# Update the PMS cache
RUN apt-get update;

#
# Ruby (via PMS)
#

# Install Ruby 1.9.x (from bearstech)
RUN apt-get -qqy install ruby1.9.3 ruby1.9.1-dev rubygems-integration && \
    apt-get clean;

#
# Puppet (via PMS)
#

# Install Puppet 3.7.x (from puppetlabs)
RUN apt-get -qqy install puppet && \
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


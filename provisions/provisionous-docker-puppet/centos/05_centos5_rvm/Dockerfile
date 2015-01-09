###############################################################################
# Provisionous Docker/Puppet RVM profile
# OS: CentOS 5 (centos5)
# Equivalent: RHEL 5, Fedora 6 (zod)
###############################################################################

FROM centos:centos5
MAINTAINER Luís Pedro Algarvio <lp.algarvio@gmail.com>

#
# Environment
#

ENV TERM linux
RUN mkdir -p /root/setup;
WORKDIR /root/setup

#
# Package Management System initialization
#

# Clear and Update the PMS cache if it is outdated
RUN ["/bin/bash", "-c", "\
    if [ -f /var/cache/yum/x86_64/5/timedhosts ]; then \
      if [ \
      \"$(stat -c %Y /var/cache/yum/x86_64/5/timedhosts)\" -lt \
      \"$(date +\"%s\" -d \"-3 days\")\" \
      ]; then yum clean all; yum makecache; \
      else echo \"PMS caches are up-to-date.\"; fi; \
    else yum clean all; yum makecache; fi;"]

#
# System dependencies and upgrades
#

# Install system dependencies
RUN yum -y install yum-fastestmirror bash-completion gnupg wget nano \
    make gcc tar procps which && \
    yum clean packages;

# Upgrade the packages
RUN yum -y upgrade && \
    yum clean packages;

#
# Repositories and GPG keys
#

# Update keys
RUN gpg --refresh-keys;

# RVM key, for alternative Ruby packages
RUN gpg --keyserver hkp://keys.gnupg.net --recv-keys D39DC0E3;

# Update the PMS cache
RUN yum makecache;

#
# RVM and Ruby (via rvm)
#

# Install RVM latest
RUN wget -q get.rvm.io | bash -s stable;

# Install system dependencies for ruby
RUN /bin/bash -l -c "rvm requirements" && \
    yum clean packages;

# Install Ruby 2.0-latest (2.2 not supported in puppet)
RUN /bin/bash -l -c "rvm install 2.0-latest";

# Set default Ruby interpreter
RUN /bin/bash -l -c "rvm use 2.0-latest --default";

#
# Rubygems (via rubygems)
#

# Configure Rubygems
RUN echo "gem: --no-ri --no-rdoc" > ~/.gemrc;

# Install Bundler latest gem
RUN /bin/bash -l -c "gem install bundler";

# Install Puppet latest and Librarian-puppet latest (for ruby >=1.9.x) gems
RUN /bin/bash -l -c "gem install puppet librarian-puppet";


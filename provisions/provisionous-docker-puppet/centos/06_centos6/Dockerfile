###############################################################################
# Provisionous Docker/Puppet profile
# OS: CentOS 6 (centos6)
# Equivalent: RHEL 6, Fedora 12 (constantine)
###############################################################################

FROM centos:centos6
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
    if [ -f /var/cache/yum/x86_64/6/timedhosts ]; then \
      if [ \
      \"$(stat -c %Y /var/cache/yum/x86_64/6/timedhosts)\" -lt \
      \"$(date +\"%s\" -d \"-3 days\")\" \
      ]; then yum clean all; yum makecache; \
      else echo \"PMS caches are up-to-date.\"; fi; \
    else yum clean all; yum makecache; fi;"]

#
# System dependencies and upgrades
#

# Install system dependencies
RUN yum -y install yum-plugin-fastestmirror which \
    gnupg ca-certificates wget curl make gcc tar procps \
    bash-completion nano && \
    yum clean packages;

# Upgrade the packages
RUN yum -y upgrade && \
    yum clean packages;

#
# Repositories and GPG keys
#

# Update keys
RUN gpg --refresh-keys;

# EPEL repo, for extra packages
RUN yum -y install epel-release;

# Puppet key/repo, for Puppet packages
RUN wget -q http://yum.puppetlabs.com/RPM-GPG-KEY-puppetlabs && \
    gpg --import RPM-GPG-KEY-puppetlabs && \
    rpm --import RPM-GPG-KEY-puppetlabs && \
    rpm -ivh http://yum.puppetlabs.com/puppetlabs-release-el-6.noarch.rpm && \
    yum clean packages;

# Update the PMS cache
RUN yum makecache;

#
# Ruby (via PMS)
#

# Install Ruby 1.8.x (from base)
RUN yum -y install ruby ruby-devel rubygems && \
    yum clean packages;

#
# Puppet (via PMS)
#

# Install Puppet 3.7.x (from puppetlabs)
RUN yum -y install puppet && \
    yum clean packages;

#
# Rubygems (via rubygems)
#

# Configure Rubygems
RUN echo "gem: --no-ri --no-rdoc" > ~/.gemrc;

# Install Bundler latest gem
RUN /bin/bash -l -c "gem install bundler";

# Install Librarian-puppet 1.4.1 (for ruby =1.8.x) gems
RUN /bin/bash -l -c "gem install librarian-puppet -v 1.4.1";


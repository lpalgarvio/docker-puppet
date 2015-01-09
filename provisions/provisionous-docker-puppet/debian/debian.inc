#!/bin/bash
#title		 :debian.inc
#description	 :Configuration for Provisionous Docker/Puppet/Debian/* images
#author		 :lpalgarvio <'lp.algarvio@gmail.com'>
#date		 :20150108
#version         :0.9
#usage		 :-
#notes		 :-
#bash_version	 :4.2
#==============================================================================

#
# Distribution information
#

# Debian GNU/Linux
declare -gA distro_info;
distro_info['status']=true;
distro_info['family']='debian';
distro_info['codename']='debian';
distro_info['title']='Debian';
distro_info['desc']='Provisionous Docker/Puppet/Debian';
distro_info['dir']='debian';
distro_info['tags']='06,06_rvm,07,07_rvm,08,08_rvm';

#
# Distribution releases/tags
#

# Debian 6 (squeeze)
declare -gA distro_tag_06;
distro_tag_06['status']=true;
distro_tag_06['version']='6';
distro_tag_06['codename']='squeeze';
distro_tag_06['title']='Debian 6 (squeeze)';
distro_tag_06['desc']='Provisionous Docker/Puppet/Debian/6 (squeeze)';
distro_tag_06['url']='solict/provisionous-puppet-debian:squeeze';
distro_tag_06['shell']='/bin/bash';
distro_tag_06['provision']=true;
distro_tag_06['provision_dir']='06_squeeze';
distro_tag_06['container']=true;
distro_tag_06['container_dir']='06_squeeze';
distro_tag_06['container_mnt']='/srv';

# Debian 6 (squeeze) RVM
declare -gA distro_tag_06_rvm;
distro_tag_06_rvm['status']=true;
distro_tag_06_rvm['version']='6_rvm';
distro_tag_06_rvm['codename']='squeeze_rvm';
distro_tag_06_rvm['title']='Debian 6 (squeeze) RVM';
distro_tag_06_rvm['desc']='Provisionous Docker/Puppet/Debian/6 (squeeze) RVM';
distro_tag_06_rvm['url']='solict/provisionous-puppet-debian:squeeze_rvm';
distro_tag_06_rvm['shell']='/bin/bash';
distro_tag_06_rvm['provision']=true;
distro_tag_06_rvm['provision_dir']='06_squeeze_rvm';
distro_tag_06_rvm['container']=true;
distro_tag_06_rvm['container_dir']='06_squeeze_rvm';
distro_tag_06_rvm['container_mnt']='/srv';

# Debian 7 (wheezy)
declare -gA distro_tag_07;
distro_tag_07['status']=true;
distro_tag_07['version']='7';
distro_tag_07['codename']='wheezy';
distro_tag_07['title']='Debian 7 (wheezy)';
distro_tag_07['desc']='Provisionous Docker/Puppet/Debian/7 (wheezy)';
distro_tag_07['url']='solict/provisionous-puppet-debian:wheezy';
distro_tag_07['shell']='/bin/bash';
distro_tag_07['provision']=true;
distro_tag_07['provision_dir']='07_wheezy';
distro_tag_07['container']=true;
distro_tag_07['container_dir']='07_wheezy';
distro_tag_07['container_mnt']='/srv';

# Debian 7 (wheezy) RVM
declare -gA distro_tag_07_rvm;
distro_tag_07_rvm['status']=true;
distro_tag_07_rvm['version']='7_rvm';
distro_tag_07_rvm['codename']='wheezy_rvm';
distro_tag_07_rvm['title']='Debian 7 (wheezy) RVM';
distro_tag_07_rvm['desc']='Provisionous Docker/Puppet/Debian/7 (wheezy) RVM';
distro_tag_07_rvm['url']='solict/provisionous-puppet-debian:wheezy_rvm';
distro_tag_07_rvm['shell']='/bin/bash';
distro_tag_07_rvm['provision']=true;
distro_tag_07_rvm['provision_dir']='07_wheezy_rvm';
distro_tag_07_rvm['container']=true;
distro_tag_07_rvm['container_dir']='07_wheezy_rvm';
distro_tag_07_rvm['container_mnt']='/srv';

# Debian 8 (jessie)
declare -gA distro_tag_08;
distro_tag_08['status']=true;
distro_tag_08['version']='8';
distro_tag_08['codename']='jessie';
distro_tag_08['title']='Debian 8 (jessie)';
distro_tag_08['desc']='Provisionous Docker/Puppet/Debian/8 (jessie)';
distro_tag_08['url']='solict/provisionous-puppet-debian:jessie';
distro_tag_08['shell']='/bin/bash';
distro_tag_08['provision']=true;
distro_tag_08['provision_dir']='08_jessie';
distro_tag_08['container']=true;
distro_tag_08['container_dir']='08_jessie';
distro_tag_08['container_mnt']='/srv';

# Debian 8 (jessie) RVM
declare -gA distro_tag_08_rvm;
distro_tag_08_rvm['status']=true;
distro_tag_08_rvm['version']='8_rvm';
distro_tag_08_rvm['codename']='jessie_rvm';
distro_tag_08_rvm['title']='Debian 8 (jessie) RVM';
distro_tag_08_rvm['desc']='Provisionous Docker/Puppet/Debian/8 (jessie) RVM';
distro_tag_08_rvm['url']='solict/provisionous-puppet-debian:jessie_rvm';
distro_tag_08_rvm['shell']='/bin/bash';
distro_tag_08_rvm['provision']=true;
distro_tag_08_rvm['provision_dir']='08_jessie_rvm';
distro_tag_08_rvm['container']=true;
distro_tag_08_rvm['container_dir']='08_jessie_rvm';
distro_tag_08_rvm['container_mnt']='/srv';


# @ node = 1
# request 4 processors
# @ tasks_per_node = 4
# @ notification = never
# @ input = /dev/null
# @ output = d.taviani/out.$(jobid)
# @ error = d.taviani/err.$(jobid)
# @ wall_clock_limit = 24:00:00
# @ job_type = parallel
# @ environment = OMP_NUM_THREADS=1
# @ requirements = (Memory >= 4096 )
# @ rset = rset_mcm_affinity
# @ mcm_affinity_options = mcm_distribute mcm_mem_pref mcm_sni_none
#
# @ node_usage = shared
# @ queue
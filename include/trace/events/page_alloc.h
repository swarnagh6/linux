#undef TRACE_SYSTEM
#define TRACE_SYSTEM page_alloc

#if !defined(_TRACE_PAGE_ALLOC_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_PAGE_ALLOC_H
/*
#include <linux/types.h>
#include <linux/list.h>
*/
#include <linux/tracepoint.h>



#ifdef CONFIG_COMPACTION
TRACE_EVENT(mm_compaction_success,
    TP_PROTO(
		struct zone *zone,
		unsigned int order,
		int ret),

	TP_ARGS(zone, order, ret),

    TP_STRUCT__entry(
		__field(int, nid)
		__field(enum zone_type, idx)
		__field(unsigned int, order)
		__field(int, ret)
	),

	TP_fast_assign(
		__entry->nid = zone_to_nid(zone);
		__entry->idx = zone_idx(zone);
		__entry->order = order;
		__entry->ret = ret;
	),

	TP_printk("node=%d zone=%-8s order=%u, res_index=%d",
		__entry->nid,
		__print_symbolic(__entry->idx, ZONE_TYPE),
		__entry->order,
		__entry->ret
		)
);

TRACE_EVENT(mm_compaction_failure,
    TP_PROTO(
		unsigned int order),

	TP_ARGS( order),

    TP_STRUCT__entry(
		__field(unsigned int, order)
	),

	TP_fast_assign(
		__entry->order = order;
	),

	TP_printk("order=%u",
		__entry->order
		)
);



#endif /* CONFIG_COMPACTION */

#endif /* _TRACE_PAGEALLOC_H */

/* This part must be outside protection */
#include <trace/define_trace.h>

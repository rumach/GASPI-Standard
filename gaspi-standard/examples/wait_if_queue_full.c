#include <wait_if_queue_full.h>
#include <success_or_die.h>

void wait_if_queue_full ( const gaspi_queue_id_t queue_id
                        , const gaspi_number_t request_size
                        )
{
  gaspi_number_t queue_size_max;
  gaspi_number_t queue_size;

  ASSERT (gaspi_queue_size_max (&queue_size_max));
  ASSERT (gaspi_queue_size (queue_id, &queue_size));

  if (queue_size + request_size >= queue_size_max)
    {
      ASSERT (gaspi_wait (queue_id, GASPI_BLOCK));
    }
}

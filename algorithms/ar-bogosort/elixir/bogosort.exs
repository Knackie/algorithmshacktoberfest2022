defmodule Bogosort do
  def sort(list) when is_list(list) do
    list
    |> is_sorted?()
    |> if do
      list
    else
      list
      |> Enum.shuffle()
      |> sort()
    end
  end

  defp is_sorted?(list) do
    Enum.reduce(list, {true, nil}, fn
      first_num, {true, nil} ->
        {true, first_num}

      num, {sorted?, last_num} ->
        {num >= last_num and sorted?, num}
    end)
    |> elem(0)
  end
end

1..5
|> Enum.shuffle()
|> IO.inspect(label: "Unsorted list")
|> Bogosort.sort()
|> IO.inspect(label: "Sorted list")

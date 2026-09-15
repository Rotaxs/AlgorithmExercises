local callout_labels = {
  note = "笔记",
  tip = "提示",
  important = "重要",
  warning = "警告",
  caution = "注意",
}

local callout_environments = {
  note = "notebox",
  tip = "tipbox",
  important = "importantbox",
  warning = "warningbox",
  caution = "warningbox",
}

function BlockQuote(block)
  if not FORMAT:match("latex") or #block.content == 0 then
    return nil
  end

  local first = block.content[1]
  if first.t ~= "Para" and first.t ~= "Plain" then
    return nil
  end

  local marker = first.content[1]
  if not marker or marker.t ~= "Str" then
    return nil
  end

  local callout_type = marker.text:match("^%[!([%w_-]+)%]$")
  if not callout_type then
    return nil
  end

  callout_type = callout_type:lower()
  local environment = callout_environments[callout_type] or "notebox"
  local label = callout_labels[callout_type] or "说明"

  table.remove(first.content, 1)
  while first.content[1]
      and (first.content[1].t == "Space"
        or first.content[1].t == "SoftBreak"
        or first.content[1].t == "LineBreak") do
    table.remove(first.content, 1)
  end
  if #first.content == 0 then
    table.remove(block.content, 1)
  end

  -- A returned outer callout is not walked again, so transform nested
  -- callouts explicitly before wrapping it in raw LaTeX blocks.
  local nested = pandoc.Div(block.content):walk({ BlockQuote = BlockQuote })
  block.content = nested.content

  local result = pandoc.List:new()
  result:insert(pandoc.RawBlock("latex", "\\begin{" .. environment .. "}{" .. label .. "}"))
  result:extend(block.content)
  result:insert(pandoc.RawBlock("latex", "\\end{" .. environment .. "}"))
  return result
end

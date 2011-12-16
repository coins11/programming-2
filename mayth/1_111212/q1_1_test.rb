open("q1_1_result", "w") do |file|
    (3..50).each do |n|
        file.puts "n = #{n}"
        file.puts `echo #{n} | ./q1_1`.gsub('height = ', '') + "\n"
    end
end
